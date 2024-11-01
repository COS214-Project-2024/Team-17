#include "MainRoads.h"
#include <iostream>
#include <cmath>
#include "../RoadStates/RoadStatesIncludes.h"

MainRoads::MainRoads(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
	// Resources::removeConcrete(BuildingRequirements::mainRoadConcreteCost);
	// Resources::removeSteel(BuildingRequirements::mainRoadSteelCost);
	// Resources::removeWood(BuildingRequirements::mainRoadWoodCost);
	// Resources::removeMoney(BuildingRequirements::mainRoadBuildCost);
}

void MainRoads::displayInfo()
{
	std::cout << "Main Road from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ")" << std::endl;
}

void MainRoads::calculateTraffic()
{
	setState(new Congested());
}

float MainRoads::getDistance()
{
	return this->distance;
}

void MainRoads::addConnection(RoadComponent *connection, float distance)
{
	connections.push_back(connection);
}

float MainRoads::calculateDistance(int x, int y)
{
	int yDiff = endY - startY;
	int xDiff = endX - startX;
	int x1y2 = startX * endY;
	int x2y1 = endX * startY;
	float dist = abs(yDiff * x - xDiff * y + x2y1 - x1y2) / sqrt(pow(yDiff, 2) + pow(xDiff, 2));

	return dist;
}

void MainRoads::notifyChange(std::string message)
{
	std::cout << "Main Road received message: " << message << std::endl;
}
