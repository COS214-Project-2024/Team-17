#include "CityCentralMediator.h"

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

CityCentralMediator::CityCentralMediator()
{
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
