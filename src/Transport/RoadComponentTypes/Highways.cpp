#include "Highways.h"
#include <iostream>
#include <cmath>
#include "../RoadStates/RoadStatesIncludes.h"

Highways::Highways(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
	Resources::removeConcrete(BuildingRequirements::highwayConcreteCost);
	Resources::removeSteel(BuildingRequirements::highwaySteelCost);
	Resources::removeWood(BuildingRequirements::highwayWoodCost);
	Resources::removeMoney(BuildingRequirements::highwayBuildCost);

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

void Highways::notifyChange(std::string message)
{
	std::cout << "Highway received message: " << message << std::endl;
}

void Highways::addConnection(RoadComponent *connection, float distance)
{
	connections.push_back(connection);
}

float Highways::calculateDistance(int x, int y)
{
	int yDiff = endY - startY;
	int xDiff = endX - startX;
	int x1y2 = startX * endY;
	int x2y1 = endX * startY;
	float dist = abs(yDiff * x - xDiff * y + x2y1 - x1y2) / sqrt(pow(yDiff, 2) + pow(xDiff, 2));

	return dist;
}
