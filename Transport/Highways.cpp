#include "Highways.h"

Highways::Highways(CityMediator *mediator) : RoadComponent(mediator)
{
}

void Highways::displayInfo()
{
	// TODO - implement Highways::displayInfo
	throw "Not yet implemented";
}

void Highways::calculateTraffic()
{
	// TODO - implement Highways::calculateTraffic
	throw "Not yet implemented";
}

float Highways::getDistance()
{
	return this->distance;
}