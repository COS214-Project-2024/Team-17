#ifndef ROADSTATE_H
#define ROADSTATE_H

#include <string>
class RoadComponent; // Use forward declaration to avoid circular dependency

class RoadState
{

public:
	virtual void handleTraffic(RoadComponent *road) = 0;

	virtual std::string getStatus() = 0;

	virtual ~RoadState() {}
};

#endif
