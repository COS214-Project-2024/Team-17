#include "RoadsComposite.h"
#include <iostream>
#include "../RoadStates/RoadStatesIncludes.h"

RoadsComposite::RoadsComposite(CityMediator *mediator) : RoadComponent(mediator)
{
}

void RoadsComposite::displayInfo()
{
	std::cout << "Composite Road of distance: " << getDistance() << std::endl;
}

void RoadsComposite::calculateTraffic()
{
	setState(new Congested());
}

void RoadsComposite::add(RoadComponent *component)
{
	components.push_back(component);
}

void RoadsComposite::remove(RoadComponent *component)
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		if (*it == component)
		{
			components.erase(it);
			break;
		}
	}
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

void RoadsComposite::notifyChange(std::string message)
{
	std::cout << "Composite Road received message: " << message << std::endl;
}
