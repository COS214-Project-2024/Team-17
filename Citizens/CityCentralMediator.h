#ifndef CITYCENTRALMEDIATOR_H
#define CITYCENTRALMEDIATOR_H

#include <vector>
#include "CityMediator.h"
#include "Citizen.h"
#include <string>

class Building;
class Utilities;
class RoadState;

class CityCentralMediator : public CityMediator
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

	/*
	@brief Notifies all citizens of a building change.
	@param building The building that changed.
	@param message The message to send to the citizens.
	*/
	void notifyBuildingChange(Building *building, std::string message);

	/*
	@brief Notifies all citizens of a utility change.
	@param type The utilities building that changed.
	@param status The new status of the utility.
	@param message The message to send to the citizens.
	*/
	void notifyUtilityChange(Utilities *type, bool status, std::string message);

	/*
	@brief Notifies all citizens of a road status change.
	@param status The road status that changed.
	@param message The message to send to the citizens.
	*/
	void notifyRoadChange(RoadState *status, std::string message);

private:
	void handlePopulationGrowth();

	void handleUtilityFailure();

	void handleTrafficStatus(RoadState *status);

	void updateCitizenSatisfaction();
};

#endif
