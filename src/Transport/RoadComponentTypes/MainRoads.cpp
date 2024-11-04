#include "MainRoads.h"
#include <iostream>
#include <cmath>
#include "../RoadStates/RoadStatesIncludes.h"
#include "../../resources.h"
#include "../../Buildings/BuildingRequirements.h"

MainRoads::MainRoads(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
	capacity = 4;
	Resources::removeConcrete(BuildingRequirements::mainRoadConcreteCost);
	Resources::removeSteel(BuildingRequirements::mainRoadSteelCost);
	Resources::removeWood(BuildingRequirements::mainRoadWoodCost);
	Resources::removeMoney(BuildingRequirements::mainRoadBuildCost);
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
	float x1 = startX;
	float y1 = startY;
	float x2 = endX;
	float y2 = endY;

	// Calculate the squared length of the line segment
	float lineSegmentLengthSquared = pow(x2 - x1, 2) + pow(y2 - y1, 2);

	if (lineSegmentLengthSquared == 0)
	{
		// If start and end points are the same, just return distance to start point
		return sqrt(pow(x - x1, 2) + pow(y - y1, 2));
	}

	// Calculate projection ratio (t)
	float t = std::max(0.0f, std::min(1.0f,
									  ((x - x1) * (x2 - x1) + (y - y1) * (y2 - y1)) / lineSegmentLengthSquared));

	// Calculate the nearest point on the line segment
	float projectionX = x1 + t * (x2 - x1);
	float projectionY = y1 + t * (y2 - y1);

	// Calculate the distance to the nearest point
	float distance = sqrt(pow(x - projectionX, 2) + pow(y - projectionY, 2));

	return distance;
}

void MainRoads::notifyChange(std::string message)
{
	std::cout << "Main Road received message: " << message << std::endl;
}
