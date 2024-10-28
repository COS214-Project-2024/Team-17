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

public:
	Citizen(CityMediator *mediator);

	void setState(CitizenState *newState);

	CitizenState *getState();

	void notifyChange(std::string message);

	void accept(TaxAndBudgetVisitor *visitor);

	std::string getName();

	~Citizen();
};

#endif