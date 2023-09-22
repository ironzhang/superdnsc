#include "filewatch/observer.h"

namespace superdnsc {

#ifdef __LINUX__

static int GetFileLastWriteTime(const string &path, uint64_t &timestamp) {
	struct stat fi;
	int ret = stat(path.c_str(), &fi);
	if (ret != 0) {
		return -1;
	}

	timestamp = fi.st_mtim.tv_sec * 1000 * 1000 * 1000 + fi.st_mtim.tv_nsec;
	return 0;
}

#elif __MACOS__

static int GetFileLastWriteTime(const string &path, uint64_t &timestamp) {
	struct stat fi;
	int ret = stat(path.c_str(), &fi);
	if (ret != 0) {
		return -1;
	}

	timestamp = fi.st_mtimespec.tv_sec * 1000 * 1000 * 1000 + fi.st_mtimespec.tv_nsec;
	return 0;
}

#else

static int GetFileLastWriteTime(const string &path, uint64_t &timestamp) {
	struct stat fi;
	int ret = stat(path.c_str(), &fi);
	if (ret != 0) {
		return -1;
	}

	timestamp = fi.st_mtim.tv_sec * 1000 * 1000 * 1000 + fi.st_mtim.tv_nsec;
	return 0;
}

#endif

FileObserver::FileObserver(const string &path, WatchFunc f, void *arg) {
	this->path = path;
	this->watchFunc = f;
	this->arg = arg;
	this->lastWatchTime = 0;
	this->quit = false;
}

void FileObserver::Observe() {
	uint64_t timestamp = 0;
	int ret = GetFileLastWriteTime(this->path, timestamp);
	if (ret != 0) {
		return;
	}
	if (timestamp > this->lastWatchTime) {
		this->lastWatchTime = timestamp;
		this->quit = this->watchFunc(this->path, this->arg);
	}
}

} // namespace superdnsc
