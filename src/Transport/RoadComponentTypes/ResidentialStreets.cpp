#include "ResidentialStreets.h"
#include <iostream>
#include "../RoadStates/RoadStatesIncludes.h"

ResidentialStreets::ResidentialStreets() : RoadComponent()
{
}

void ResidentialStreets::displayInfo()
{
	std::cout << "Residential Street of distance: " << distance << std::endl;
}

void ResidentialStreets::calculateTraffic()
{
	setState(new Congested());
}

float ResidentialStreets::getDistance()
{
	return this->distance;
}

void ResidentialStreets::notifyChange(std::string message)
{
	std::cout << "Residential Street received message: " << message << std::endl;
}
