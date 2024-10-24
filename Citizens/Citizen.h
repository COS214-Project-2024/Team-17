#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenStates/CitizenStatesIncludes.h"
#include "CityBlock.h"
#include "CityMediator.h"

class Citizen : CityBlock
{

private:
	int population;
	CityMediator *mediator;
	CitizenState state;

public:
	Citizen(CityMediator *mediator);

	void setState(CitizenState newState);

	CitizenState getState();

	void notifyChange();

	void accept(TaxAndBudgetVisitor *visitor);
};

#endif
