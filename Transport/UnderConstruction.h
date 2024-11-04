#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

class UnderConstruction : RoadState {


public:
	void handleTraffic(RoadComponent& road);

	string getStatus();
};

#endif
