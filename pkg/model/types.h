#ifndef SUPERDNSC_MODEL_TYPES_H
#define SUPERDNSC_MODEL_TYPES_H

#include "commlib/comminc.h"

namespace superdnsc {

// State 地址状态
typedef string State;

const Enabled = "enabled";
const Disabled = "disabled";

class Endpoint {
public:
	string addr;
	State state;
	int weight;
};

class Cluster {
public:
	string name;
	map<string, string> features;
	vector<Endpoint> endpoints;
};

} // namespace superdnsc

#endif
