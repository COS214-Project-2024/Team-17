#include "RoadIteratorCon.h"
#include "../RoadComponent.h"

RoadIteratorCon::RoadIteratorCon(std::vector<RoadComponent *> *roads)
{
	this->roads = roads;
}

void RoadIteratorCon::first()
{
	current = 0;
}

void RoadIteratorCon::next()
{
	current++;
}

bool RoadIteratorCon::isDone()
{
	return current >= roads->size();
}

RoadComponent *RoadIteratorCon::currentRoad()
{
	return roads->at(current);
}
