#ifndef SUPERDNSC_FILEWATCH_WATCHER_H
#define SUPERDNSC_FILEWATCH_WATCHER_H

#include "filewatch/observer.h"

namespace superdnsc {

// FileWatcher 文件订阅程序
class FileWatcher {
public:
	FileWatcher(int interval);

	~FileWatcher();

	// WatchFile 订阅文件
	int WatchFile(const string &path, WatchFunc f, void *arg);

private:
	static void ThreadRun(FileWatcher *w);
	void Running();
	void Tick();

private:
	int interval;        // 观察间隔，单位：秒
	bool closed;         // 关闭标记
	ThreadPtr threadPtr; // 线程对象

	mutex mu;                        // 文件观察对象列表并发保护锁
	list<FileObserverPtr> observers; // 文件观察对象列表
};

} // namespace superdnsc

#endif
