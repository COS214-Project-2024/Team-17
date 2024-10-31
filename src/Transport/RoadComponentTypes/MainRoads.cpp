#include "MainRoads.h"
#include <iostream>
#include <cmath>
#include "../RoadStates/RoadStatesIncludes.h"

MainRoads::MainRoads(int sX, int sY, int eX, int eY) : RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;
}

void MainRoads::displayInfo()
{
	std::cout << "Main Road of distance: " << distance << std::endl;
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

void MainRoads::notifyChange(std::string message)
{
	std::cout << "Main Road received message: " << message << std::endl;
}
