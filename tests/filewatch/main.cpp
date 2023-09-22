#include <iostream>

#include "filewatch/watcher.h"

static bool OnWatch(const string &path, void *arg) {
	cout << path << endl;
	return false;
}

void Run() {
	superdnsc::FileWatcher fw(1);
	fw.WatchFile("a.txt", OnWatch, nullptr);
	fw.WatchFile("b.txt", OnWatch, nullptr);

	while (true) {
		string cmd;
		cin >> cmd;
		if (cmd == "quit") {
			break;
		}
	}
}

int main() {
	Run();
	sleep(2);
	return 0;
}
