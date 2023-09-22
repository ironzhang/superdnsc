#include "filewatch/watcher.h"

namespace superdnsc {

FileWatcher::FileWatcher(int interval)
	:interval(interval), closed(false) {
	this->threadPtr = ThreadPtr(new thread(FileWatcher::ThreadRun, this));
}

FileWatcher::~FileWatcher() {
	this->closed = true;
	this->threadPtr->join(); // 等待线程退出
}

int FileWatcher::WatchFile(const string &path, WatchFunc f, void *arg) {
	FileObserverPtr fo = FileObserverPtr(new FileObserver(path, f, arg));
	if (fo == nullptr) {
		return -1;
	}
	fo->Observe();

	lock_guard<mutex> guard(this->mu);
	this->observers.push_back(fo);
	return 0;
}

void FileWatcher::ThreadRun(FileWatcher *w) {
	w->Running();
}

void FileWatcher::Running() {
	int now = 0, next = 0;
	while(!this->closed) {
		now = time(NULL);
		if (now >= next) {
			this->Tick();
			next = now + this->interval;
		}
		sleep(1);
	}
}

void FileWatcher::Tick() {
	lock_guard<mutex> guard(this->mu);

	auto it = this->observers.begin();
	while (it != this->observers.end()) {
		FileObserverPtr fo = *it;
		fo->Observe();
		if (fo->quit) {
			it = this->observers.erase(it);
		} else {
			++it;
		}
	}
}

} // namespace superdnsc
