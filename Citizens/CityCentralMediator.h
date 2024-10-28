#ifndef CITYCENTRALMEDIATOR_H
#define CITYCENTRALMEDIATOR_H

#include <vector>
#include "CityMediator.h"
#include "Citizen.h"

class CityCentralMediator : public CityMediator {

private:
	vector<Building*> buildings;
	UtilityManager* utilities;
	vector<Citizen*> citizens;
	RoadComponent* roadState;

public:
	void registerBuilding(Building* building);

	void registerUtility(UtilityManager* util);

	void notifyBuildingChange(Building* building);

	void notifyUtilityChange(UtilityManager* type, bool status);

	void notifyRoadChange(RoadComponent* status);

private:
	void handlePopulationGrowth();

	void handleUtilityFailure();

	void handleTrafficStatus(RoadComponent* status);

	void updateCitizenSatisfaction();
};

#endif
