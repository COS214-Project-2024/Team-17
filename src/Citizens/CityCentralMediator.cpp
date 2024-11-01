#include "CityCentralMediator.h"
#include "../../colours.h"
#include <iostream>
#include "../Transport/TransportInclude.h"
#include <set>

static CityCentralMediator *instance = nullptr;

RoadComponent *CityCentralMediator::getClosestRoad(int x, int y)
{
	RoadIterator *seq = new RoadIteratorCon(&roads);
	seq->first();
	RoadComponent *closest = seq->currentRoad();
	float distance = INT32_MAX;

	while (!seq->isDone())
	{
		float dist = seq->currentRoad()->calculateDistance(x, y);
		if (dist < distance)
		{
			distance = dist;
			closest = seq->currentRoad();
		}
		seq->next();
	}

	// Try cast to RoadsComposite
	RoadsComposite *composite = dynamic_cast<RoadsComposite *>(closest);
	if (composite != nullptr)
	{
		std::vector<RoadComponent *> components = composite->getComponents();
		for (auto c : components)
		{
			c->displayInfo();
			float dist = c->calculateDistance(x, y);
			if (dist <= distance)
			{
				distance = dist;
				closest = c;
			}
		}
	}

	return closest;
}

CityCentralMediator *CityCentralMediator::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CityCentralMediator("all good!");
	}
	return instance;
}

void CityCentralMediator::registerBuilding(Building *building)
{
	buildings.push_back(building);
}

void CityCentralMediator::registerUtility(UtilityManager *util)
{
	utilities.push_back(util);
}

void CityCentralMediator::registerCitizen(Citizen *citizen)
{
	citizens.push_back(citizen);
	std::cout << "Citizen " << citizen->getName() << " registered" << std::endl;
}

void CityCentralMediator::registerRoad(RoadComponent *road)
{
	roads.push_back(road);
}

void CityCentralMediator::notifyBuildingChange(Building *building, std::string message = "")
{
	for (auto c : citizens)
	{
		c->notifyChange(message);
	}
}

void CityCentralMediator::notifyUtilityChange(UtilityManager *type, bool status, std::string message = "")
{
	for (auto c : citizens)
	{
		c->notifyChange(message);
	}
}

void CityCentralMediator::notifyRoadChange(RoadState *status, std::string message = "")
{
	for (auto c : citizens)
	{
		c->notifyChange(message);
	}
}

CityCentralMediator::CityCentralMediator(std::string param)
{
	if (param == "error")
	{
		std::cout << RED << "Error: CityCentralMediator is a singleton. Use CityCentralMediator::getInstance() instead." << RESET << std::endl;
	}
}

std::vector<RoadComponent *> CityCentralMediator::calculateRoute(int startX, int startY, int endX, int endY)
{
	std::set<RoadComponent *> visited;
	std::vector<RoadComponent *> path;
	RoadComponent *current = getClosestRoad(startX, startY);
	RoadComponent *end = getClosestRoad(endX, endY);

	while (current != end)
	{
		path.push_back(current);
		visited.insert(current);
		std::vector<RoadComponent *> connections = current->getConnections();
		float distance = 999999;
		RoadComponent *next = nullptr;

		for (auto c : connections)
		{
			if (visited.find(c) == visited.end())
			{
				float dist = c->calculateDistance(endX, endY);
				if (dist < distance)
				{
					distance = dist;
					next = c;
				}
			}
		}

		if (next == nullptr)
		{
			std::cout << RED << "Error: No path found." << RESET << std::endl;
			return path;
		}

		current = next;
	}
	path.push_back(current);
	return path;
}

CityCentralMediator::~CityCentralMediator()
{
	instance = nullptr;
}

void CityCentralMediator::handlePopulationGrowth()
{
	// TODO - implement CityCentralMediator::handlePopulationGrowth
	throw "Not yet implemented";
}

void CityCentralMediator::handleUtilityFailure()
{
	// TODO - implement CityCentralMediator::handleUtilityFailure
	throw "Not yet implemented";
}

void CityCentralMediator::handleTrafficStatus(RoadState *status)
{
	// TODO - implement CityCentralMediator::handleTrafficStatus
	throw "Not yet implemented";
}

void CityCentralMediator::updateCitizenSatisfaction()
{
	for (auto c : citizens)
	{
		int random = rand() % 5;
		CitizenState *newState = NULL;

		switch (random)
		{
		case 0:
			newState = new Happy();
			break;
		case 1:
			newState = new Content();
			break;
		case 2:
			newState = new Indifferent();
			break;
		case 3:
			newState = new Discontent();
			break;
		case 4:
			newState = new Upset();
			break;

		default:
			break;
		}

		c->setState(newState);
	}
}
