#include "MainRoads.h"
#include <iostream>
#include "../RoadStates/RoadStatesIncludes.h"

MainRoads::MainRoads(CityMediator *mediator) : RoadComponent(mediator)
{
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

void MainRoads::notifyChange(std::string message)
{
	std::cout << "Main Road received message: " << message << std::endl;
}
