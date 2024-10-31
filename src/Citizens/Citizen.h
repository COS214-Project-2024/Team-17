#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenStates/CitizenStatesIncludes.h"
#include "CityBlock.h"
#include "CityMediator.h"
#include <string>

class Citizen : CityBlock
{

private:
	int population;
	CityMediator *mediator;
	CitizenState *state;
	std::string name;
	Building *workplace;

public:
	Citizen();

	void setState(CitizenState *newState);

	CitizenState *getState();

	void notifyChange(std::string message);

	void accept(TaxAndBudgetVisitor *visitor);

	std::string getName();

	void setWorkplace(Building *workplace);

	Building *getWorkplace();

	void fired();

	~Citizen();
};

#endif