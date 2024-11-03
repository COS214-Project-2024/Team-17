#ifndef CITIZEN_H
#define CITIZEN_H

class Citizen : CityBlock {

private:
	int population;
	CityMediator* mediator;
	CitizenState state;

public:
	Citizen(CityMediator* mediator);

	void setState(CitizenState newState);

	void notifyChange();

	void accept(TaxAndBudgetVisitor* visitor);
};

#endif
