#include "Highways.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include "../RoadStates/RoadStatesIncludes.h"
#include "../../resources.h"
#include "../../Buildings/BuildingRequirements.h"

Highways::Highways(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
	capacity = 6;
	// Resources::removeConcrete(BuildingRequirements::highwayConcreteCost);
	// Resources::removeSteel(BuildingRequirements::highwaySteelCost);
	// Resources::removeWood(BuildingRequirements::highwayWoodCost);
	// Resources::removeMoney(BuildingRequirements::highwayBuildCost);
}

void Highways::displayInfo()
{
	std::cout << "Highway from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ")" << std::endl;
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
