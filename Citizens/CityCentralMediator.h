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
	std::vector<Building *> buildings;
	Utilities *utilities;
	std::vector<Citizen *> citizens;
	RoadState *roadState;

public:
	void registerBuilding(Building *building);

	void registerUtility(Utilities *util);

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
