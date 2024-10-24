#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "RoadState.h"
#include "RoadComponent.h"
#include <string>

class UnderConstruction : RoadState
{

public:
	void handleTraffic(RoadComponent &road);

	std::string getStatus();
};

#endif
