#include "RoadsComposite.h"
#include <iostream>
#include <cmath>
#include "../../../colours.h"
#include "../RoadStates/RoadStatesIncludes.h"
#include "RoadComponentTypesIncludes.h"

static const int MAX_SECTION_DISTANCE = 50;

RoadsComposite::RoadsComposite(int sX, int sY, int eX, int eY, std::string type)
	: RoadComponent(sX, sY, eX, eY)
{
	float totalDistance = sqrt(pow(eX - sX, 2) + pow(eY - sY, 2));
	distance = totalDistance;

	int numSections = ceil(totalDistance / MAX_SECTION_DISTANCE);
	for (int i = 0; i < numSections; i++)
	{
		float sectionDistance = totalDistance -= MAX_SECTION_DISTANCE;
		int ssX = sX + (eX - sX) * i / numSections;
		int ssY = sY + (eY - sY) * i / numSections;
		int eeX = sX + (eX - sX) * (i + 1) / numSections;
		int eeY = sY + (eY - sY) * (i + 1) / numSections;
		if (type == "highway")
		{
			add(new Highways(ssX, ssY, eeX, eeY));
		}
		else if (type == "main")
		{
			add(new MainRoads(ssX, ssY, eeX, eeY));
		}
		else if (type == "residential")
		{
			add(new ResidentialStreets(ssX, ssY, eeX, eeY));
		}
	}

	// Link the sections
	for (int i = 0; i < numSections - 1; i++)
	{
		components[i]->addConnection(components[i + 1], MAX_SECTION_DISTANCE);
		components[i + 1]->addConnection(components[i], 0);
	}
}

void RoadsComposite::displayInfo()
{
	std::cout << "Composite Road of distance: " << getDistance() << std::endl;
}

void RoadsComposite::calculateTraffic()
{
	setState(new Congested());
}

void RoadsComposite::add(RoadComponent *component)
{
	components.push_back(component);
}

void RoadsComposite::remove(RoadComponent *component)
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		if (*it == component)
		{
			components.erase(it);
			break;
		}
	}
}

float RoadsComposite::getDistance()
{
	float sumDistance = 0;
	for (auto component : components)
	{
		sumDistance += component->getDistance();
	}
	return sumDistance;
}

void RoadsComposite::notifyChange(std::string message)
{
	std::cout << "Composite Road received message: " << message << std::endl;
}

void RoadsComposite::addConnection(RoadComponent *connection, float distance)
{
	float td = getDistance();
	if (distance < 0 || distance > td)
	{
		std::cout << RED << "Invalid distance for connection" << RESET << std::endl;
		return;
	}

	int idx = 0;
	while (distance > components[idx]->getDistance())
	{
		distance -= components[idx]->getDistance();
		idx++;
	}

	components[idx]->addConnection(connection, distance);
}

std::vector<RoadComponent *> RoadsComposite::getConnections()
{
	std::vector<RoadComponent *> result;
	for (auto component : components)
	{
		std::vector<RoadComponent *> temp = component->getConnections();
		result.insert(result.end(), temp.begin(), temp.end());
	}
	return result;
}

float RoadsComposite::calculateDistance(int x, int y)
{
	// Calculate the shortest distance from the point to the road

	float shortest = INT32_MAX;
	for (auto component : components)
	{
		float dist = component->calculateDistance(x, y);
		if (dist < shortest)
		{
			shortest = dist;
		}
	}

	return shortest;
}
