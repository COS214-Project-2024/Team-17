#include "RoadsComposite.h"
#include <iostream>
#include <cmath>
#include "../../../colours.h"
#include "../RoadStates/RoadStatesIncludes.h"
#include "RoadComponentTypesIncludes.h"
#include "../../Citizens/CityCentralMediator.h"

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

	CityCentralMediator::getInstance()->registerRoad(this);
}

void RoadsComposite::displayInfo()
{
	std::cout << "Composite Road from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ")" << std::endl;
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

	RoadsComposite *conn = dynamic_cast<RoadsComposite *>(connection);
	if (conn != nullptr)
	{
		// Calculate x and y value of the distance of the entire roads composite
		int x = startX + (endX - startX) * distance / td;
		int y = startY + (endY - startY) * distance / td;

		// Get the closest section to the x and y value
		RoadComponent *closest = conn->closestSection(x, y);
		if (closest == nullptr)
		{
			std::cout << RED << "Could not find closest section" << RESET << std::endl;
			return;
		}
		closest->addConnection(components[idx], distance);
		components[idx]->addConnection(closest, distance);
	}
	else
	{
		components[idx]->addConnection(connection, distance);
	}
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

const std::vector<RoadComponent *> &RoadsComposite::getComponents() const
{
	return components;
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

RoadComponent *RoadsComposite::closestSection(int x, int y)
{
	float distance = INT32_MAX;
	RoadComponent *closest = nullptr;

	for (auto component : components)
	{
		float dist = component->calculateDistance(x, y);
		if (dist < distance)
		{
			distance = dist;
			closest = component;
		}
	}

	return closest;
}
