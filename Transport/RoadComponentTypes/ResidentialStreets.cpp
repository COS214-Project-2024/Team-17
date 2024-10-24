#include "ResidentialStreets.h"
#include <iostream>
#include "../RoadStates/RoadStatesIncludes.h"

ResidentialStreets::ResidentialStreets(CityMediator *mediator) : RoadComponent(mediator)
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
