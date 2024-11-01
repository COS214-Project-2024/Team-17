#include "CityCentralMediator.h"
#include "../../colours.h"
#include <iostream>
#include "../Transport/TransportInclude.h"
#include <set>
#include <queue>
#include <unordered_map>
#include <limits>
#include "Bus.h"

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

void CityCentralMediator::registerBus(Bus *bus)
{
	buses.push_back(bus);
	std::cout << "Bus registered" << std::endl;
}

void CityCentralMediator::registerRoad(RoadComponent *road)
{
	roads.push_back(road);
}

void CityCentralMediator::registerTrainStation(Trainstation *trainStation)
{
	trainStations.push_back(trainStation);
	std::cout << "Trainstation registered" << std::endl;
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

void CityCentralMediator::notifyBusReady(Bus *bus)
{
	// push bus to busQueue if not in queue already
	if (std::find(busQueue.begin(), busQueue.end(), bus) == busQueue.end())
	{
		busQueue.push_back(bus);
		std::cout << "Bus added to queue" << std::endl;
	}
}

Bus *CityCentralMediator::requestBus(Citizen *citizen, RoadComponent *location)
{
	if (busQueue.empty())
	{
		std::cout << "No buses available" << std::endl;
		return nullptr;
	}
	else
	{
		Bus *bus = busQueue.front();
		busQueue.erase(busQueue.begin());
		bus->addPassenger(nullptr, location);
		return bus;
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
	if (!isReachableByRoad(startX, startY) || !isReachableByRoad(endX, endY))
	{
		std::cout << RED << "Error: Start or end point is not reachable by road." << RESET << std::endl;
		return std::vector<RoadComponent *>();
	}
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

std::vector<RoadComponent *> CityCentralMediator::calculateRoute(RoadComponent *start, RoadComponent *end)
{
	// Priority queue to store the nodes to be explored, prioritized by their current shortest distance
	std::priority_queue<std::pair<float, RoadComponent *>, std::vector<std::pair<float, RoadComponent *>>, std::greater<std::pair<float, RoadComponent *>>> pq;

	// Map to store the shortest distance to each node
	std::unordered_map<RoadComponent *, float> distances;

	// Map to store the previous node in the shortest path
	std::unordered_map<RoadComponent *, RoadComponent *> previous;

	// Initialize distances to infinity, except the start node
	for (auto road : roads)
	{
		RoadsComposite *composite = dynamic_cast<RoadsComposite *>(road);
		if (composite != nullptr)
		{
			for (auto c : composite->getComponents())
			{
				distances[c] = std::numeric_limits<float>::infinity();
			}
		}
		else
		{
			distances[road] = std::numeric_limits<float>::infinity();
		}
	}
	distances[start] = 0.0f;

	// Add the start node to the priority queue
	pq.push({0.0f, start});

	while (!pq.empty())
	{
		// Extract the node with the smallest distance
		RoadComponent *current = pq.top().second;
		pq.pop();

		// If this node is the destination, reconstruct the path and return it
		if (current == end)
		{
			std::vector<RoadComponent *> path;
			while (current != nullptr)
			{
				path.push_back(current);
				current = previous[current];
			}
			std::reverse(path.begin(), path.end());
			return path;
		}

		// For each neighbor of the current node
		for (auto neighbor : current->getConnections())
		{
			// Assume a uniform distance of 1 between connected nodes
			float newDist = distances[current] + 1;

			// If this distance is shorter than the previously known distance
			if (newDist < distances[neighbor])
			{
				// Update the distance and add the neighbor to the priority queue
				distances[neighbor] = newDist;
				previous[neighbor] = current;
				pq.push({newDist, neighbor});
			}
		}
	}

	// If the destination is not reachable, return an empty path
	std::cout << RED << "Error: No path found." << RESET << std::endl;
	return std::vector<RoadComponent *>();
}

bool CityCentralMediator::isReachableByRoad(int x, int y)
{
	RoadComponent *road = getClosestRoad(x, y);
	road->displayInfo();
	if (road->calculateDistance(x, y) < BUILDING_ROAD_DISTANCE)
	{
		return true;
	}
	return false;
}

Trainstation *CityCentralMediator::trainstationInRange(int x, int y)
{
	Trainstation *closest = nullptr;

	for (auto t : trainStations)
	{
		if (t->pointInRange(x, y))
		{
			closest = t;
			break;
		}
	}

	return closest;
}

void CityCentralMediator::updateBuses()
{
	for (auto b : buses)
	{
		b->doSomething();
	}
}

void CityCentralMediator::citizensDoSomething()
{
	for (auto c : citizens)
	{
		c->doSomething();
	}
}

void CityCentralMediator::citizensStartWork()
{
	for (auto c : citizens)
	{
		c->notifyChange("Go_Work");
	}
}

void CityCentralMediator::citizensEndWork()
{
	for (auto c : citizens)
	{
		c->notifyChange("Go_Home");
	}
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
