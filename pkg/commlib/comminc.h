#ifndef SUPERDNSC_COMM_COMMINC_H
#define SUPERDNSC_COMM_COMMINC_H

#include <map>
#include <list>
#include <vector>
#include <string>
#include <mutex>
#include <atomic>
#include <thread>

#include <unistd.h>
#include <sys/stat.h>

using namespace std;

// ThreadPtr 线程指针
typedef shared_ptr<thread> ThreadPtr;

#endif
