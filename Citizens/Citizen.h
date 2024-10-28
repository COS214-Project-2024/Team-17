#ifndef CITIZEN_H
#define CITIZEN_H

#include "CityBlock.h"
#include "CitizenState.h"
#include "CitizenStates/Indifferent.h"


class Citizen : CityBlock {

private:
	CityMediator* mediator;
	CitizenState* state;

public:
	Citizen(CityMediator* mediator);

	void setState(CitizenState* newState);

	CitizenState* getState();

	void notifyChange();

	void accept(TaxAndBudgetVisitor* visitor);
};

#endif
