#include "Citizen.h"

Citizen::Citizen(CityMediator* mediator) {
	// TODO - implement Citizen::Citizen
	throw "Not yet implemented";
}

void Citizen::setState(CitizenState newState) {
	this->state = newState;
}

void Citizen::notifyChange() {
	// TODO - implement Citizen::notifyChange
	throw "Not yet implemented";
}

void Citizen::accept(TaxAndBudgetVisitor* visitor) {
	// TODO - implement Citizen::accept
	throw "Not yet implemented";
}
