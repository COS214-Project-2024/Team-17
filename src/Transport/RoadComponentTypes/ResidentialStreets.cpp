#include "ResidentialStreets.h"
#include <iostream>
#include "../RoadStates/RoadStatesIncludes.h"
#include <cmath>

ResidentialStreets::ResidentialStreets(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
	// Resources::removeConcrete(BuildingRequirements::residentialStreetConcreteCost);
	// Resources::removeSteel(BuildingRequirements::residentialStreetSteelCost);
	// Resources::removeWood(BuildingRequirements::residentialStreetWoodCost);
	// Resources::removeMoney(BuildingRequirements::residentialStreetBuildCost);
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

void ResidentialStreets::addConnection(RoadComponent *connection, float distance)
{
	connections.push_back(connection);
}

float ResidentialStreets::calculateDistance(int x, int y)
{
	int yDiff = endY - startY;
	int xDiff = endX - startX;
	int x1y2 = startX * endY;
	int x2y1 = endX * startY;
	float dist = abs(yDiff * x - xDiff * y + x2y1 - x1y2) / sqrt(pow(yDiff, 2) + pow(xDiff, 2));

	return dist;
}

void ResidentialStreets::notifyChange(std::string message)
{
	std::cout << "Residential Street received message: " << message << std::endl;
}
