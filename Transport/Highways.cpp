#include "Highways.h"
#include <iostream>
#include "Congested.h"

Highways::Highways(CityMediator *mediator) : RoadComponent(mediator)
{
}

void Highways::displayInfo()
{
	std::cout << "Highway of distance: " << distance << std::endl;
}

void Highways::calculateTraffic()
{
	setState(new Congested());
}

float Highways::getDistance()
{
	return this->distance;
}