#ifndef CITYCENTRALMEDIATOR_H
#define CITYCENTRALMEDIATOR_H

#include <vector>
#include "CityMediator.h"
#include "Citizen.h"
class Building;
class Utilities;
class RoadState;

class CityCentralMediator : CityMediator
{

private:
	/*
	@brief Stores the array of buildings in the city.
	*/
	std::vector<Building *> buildings;

	/*
	@brief Stores the array of utilities in the city.
	*/
	std::vector<Utilities *> utilities;

	/*
	@brief Stores the array of citizens in the city.
	*/
	std::vector<Citizen *> citizens;
	RoadState *roadState;

public:
	/*
	@brief Registers a building with the mediator.
	@param building The building to register.
	*/
	void registerBuilding(Building *building);

	/*
	@brief Registers a utility with the mediator.
	@param util The utility to register.
	*/
	void registerUtility(Utilities *util);

	/*
	@brief Registers a citizen with the mediator.
	@param citizen The citizen to register.
	*/
	void registerCitizen(Citizen *citizen);

	void notifyBuildingChange(Building *building);

	void notifyUtilityChange(Utilities *type, bool status);

	void notifyRoadChange(RoadState *status);

private:
	void handlePopulationGrowth();

	void handleUtilityFailure();

	void handleTrafficStatus(RoadState *status);

	void updateCitizenSatisfaction();
};

#endif
