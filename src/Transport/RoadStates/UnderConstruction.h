#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "../RoadState.h"
#include <string>

class UnderConstruction : public RoadState
{
public:
	virtual void handleTraffic(RoadComponent *road);

	virtual std::string getStatus();
};

#endif
