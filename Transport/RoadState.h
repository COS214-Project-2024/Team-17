#ifndef ROADSTATE_H
#define ROADSTATE_H

class RoadState {


public:
	virtual void handleTraffic(RoadComponent& road) = 0;

	virtual string getStatus() = 0;
};

#endif
