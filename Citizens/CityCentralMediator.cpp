#include "CityCentralMediator.h"

void CityCentralMediator::registerBuilding(Building *building)
{
	buildings.push_back(building);
}

void CityCentralMediator::registerUtility(Utilities *util)
{
	utilities.push_back(util);
}

void CityCentralMediator::registerCitizen(Citizen *citizen)
{
	citizens.push_back(citizen);
}

void CityCentralMediator::notifyBuildingChange(Building *building, std::string message = "")
{
	// TODO - implement CityCentralMediator::notifyBuildingChange
	throw "Not yet implemented";
}

void CityCentralMediator::notifyUtilityChange(Utilities *type, bool status, std::string message = "")
{
	// TODO - implement CityCentralMediator::notifyUtilityChange
	throw "Not yet implemented";
}

void CityCentralMediator::notifyRoadChange(RoadState *status, std::string message = "")
{
	// TODO - implement CityCentralMediator::notifyRoadChange
	throw "Not yet implemented";
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
	// TODO - implement CityCentralMediator::updateCitizenSatisfaction
	throw "Not yet implemented";
}
