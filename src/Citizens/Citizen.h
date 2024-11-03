#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenStates/CitizenStatesIncludes.h"
#include "CityBlock.h"
#include "CityMediator.h"
#include <string>
#include <vector>

class Bus;
class RoadComponent;

class Citizen : CityBlock
{

protected:
	CitizenState *state;
	std::string name;
	Building *workplace;
	Building *home;
	Building *currentLocation;
	RoadComponent *currentRoad;
	std::vector<RoadComponent *> route;
	CityMediator *mediator = nullptr;
	Bus *myBus;
	bool ownsCar;
	bool scheduledForDeletion = false;
	int waitTimer = 0;
	enum Activity
	{
		Rest,
		Work,
		TryBusWork,
		InTransitWork,
		AwaitTransitWork,
		TryBusHome,
		InTransitHome,
		AwaitTransitHome,
		Nothing
	};

	Activity activity;

	void changeHappiness(int change);

public:
	Citizen(bool autoRegister = true);

	void setState(CitizenState *newState);

	CitizenState *getState();

	void notifyChange(std::string message);

	void accept(TaxAndBudgetVisitor *visitor);

	std::string getName();

	void setWorkplace(Building *workplace);

	Building *getWorkplace();

	void fired();

	void setHome(Building *home);

	Building *getHome();

	void evicted();

	void giveCar();

	virtual void doSomething();

	Building *getCurrentBuilding();

	int getHappiness();

	double getTax();

	~Citizen();
};

#endif