#ifndef CITYCENTRALMEDIATOR_H
#define CITYCENTRALMEDIATOR_H

class CityCentralMediator : CityMediator {

private:
	vector<Building*> buildings;
	Utilities* utilities;
	vector<Citizen*> citizens;
	RoadState roadState;

public:
	void registerBuilding(Building* building);

	void registerUtility(Utilities* util);

	void notifyBuildingChange(Building* building);

	void notifyUtilityChange(UtilityType type, bool status);

	void notifyRoadChange(RoadStatus status);

private:
	void handlePopulationGrowth();

	void handleUtilityFailure();

	void handleTrafficStatus(TrafficStatus status);

	void updateCitizenSatisfaction();
};

#endif
