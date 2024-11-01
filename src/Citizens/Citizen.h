#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenStates/CitizenStatesIncludes.h"
#include "CityBlock.h"
#include "CityMediator.h"
#include <string>

class Bus;
class RoadComponent;

class Citizen : CityBlock
{

protected:
	int population;
	CitizenState *state;
	std::string name;
	Building *workplace;
	Building *home;
	Building *currentLocation;
	RoadComponent *currentRoad;
	CityMediator *mediator;
	Bus *myBus;
	bool ownsCar;
	enum Activity
	{
		Rest,
		Work,
		InTransitWork,
		AwaitTransitWork,
		InTransitHome,
		AwaitTransitHome,
		Nothing
	};

	Activity activity;

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

	~Citizen();
};

#endif