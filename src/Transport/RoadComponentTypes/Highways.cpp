#include "Highways.h"
#include <iostream>
#include <cmath>
#include "../RoadStates/RoadStatesIncludes.h"

Highways::Highways(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
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
