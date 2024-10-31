#include "ResidentialStreets.h"
#include <iostream>
#include "../RoadStates/RoadStatesIncludes.h"
#include <cmath>

ResidentialStreets::ResidentialStreets(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
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
