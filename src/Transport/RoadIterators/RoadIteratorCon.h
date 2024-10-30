#ifndef ROADITERATORCON_H
#define ROADITERATORCON_H

#include "../RoadIterator.h"
#include <vector>

class RoadIteratorCon : public RoadIterator
{
private:
	int current;
	std::vector<RoadComponent *> *roads;

public:
	RoadIteratorCon(std::vector<RoadComponent *> *roads);

	virtual void first();

	virtual void next();

	virtual bool isDone();

	virtual RoadComponent *currentRoad();
};

#endif
