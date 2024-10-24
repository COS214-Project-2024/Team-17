#include "RoadsComposite.h"
#include <iostream>
#include "Congested.h"

RoadsComposite::RoadsComposite(CityMediator *mediator) : RoadComponent(mediator)
{
}

void RoadsComposite::displayInfo()
{
	std::cout << "Composite Road of distance: " << distance << std::endl;
}

void RoadsComposite::calculateTraffic()
{
	setState(new Congested());
}

void RoadsComposite::add(RoadComponent *component)
{
	// TODO - implement RoadsComposite::add
	throw "Not yet implemented";
}

void RoadsComposite::remove(RoadComponent *component)
{
	// TODO - implement RoadsComposite::remove
	throw "Not yet implemented";
}

float RoadsComposite::getDistance()
{
	float sumDistance = 0;
	for (auto component : components)
	{
		sumDistance += component->getDistance();
	}
	return sumDistance;
}
