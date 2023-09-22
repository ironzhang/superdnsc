#ifndef SUPERDNSC_SUPERDNS_RESOLVER_H
#define SUPERDNSC_SUPERDNS_RESOLVER_H

#include <map>
#include <vector>

using namespace std;

namespace superdnsc {
namespace superdns {

// Zone 分区信息
struct Zone {
	const char *Environment;            // 环境
	const char *Region;                 // 地域
	const char *Lidc;                   // 逻辑机房
	// map<string, string> RouteTags; // 路由标签
};

// LoadBalancer 负载均衡器接口
class LoadBalancer {
public:
	virtual ~LoadBalancer() {}
	virtual int Pickup(string domain, string cluster, const vector<string> &endpoints, string &endpoint) = 0;
};

// Resolver 服务发现解析程序
class Resolver {
private:
	Zone zone;
	LoadBalancer *loadBalancer;
	bool skipPreloadError;
	resolver *resolver;
};

} // namespace superdns
} // namespace superdnsc
