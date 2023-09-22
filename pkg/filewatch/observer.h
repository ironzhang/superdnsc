#ifndef SUPERDNSC_FILEWATCH_OBSERVER_H
#define SUPERDNSC_FILEWATCH_OBSERVER_H

#include "commlib/comminc.h"

namespace superdnsc {

// WatchFunc 订阅回调函数
//
// 返回 true 表示退出订阅，返回 false 表示继续订阅
typedef bool (*WatchFunc)(const string &path, void *arg);

// FileObserver 文件观察器
class FileObserver {
public:
	// FileObserver 构造函数
	FileObserver(const string &path, WatchFunc f, void *arg);

	// Observe 执行文件观察任务
	void Observe();

public:
	string path;            // 文件路径
	WatchFunc watchFunc;    // 订阅回调函数
	void *arg;              // 回调函数参数
	uint64_t lastWatchTime; // 最后一次执行订阅回调函数的时间戳
	bool quit;              // 退出订阅标记
};

// FileObserverPtr 文件观察器指针
typedef shared_ptr<FileObserver> FileObserverPtr;

} // namespace superdnsc

#endif
