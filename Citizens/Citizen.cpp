#include "Citizen.h"

Citizen::Citizen(CityMediator* mediator) : CityBlock(mediator) {
	this->mediator = mediator;
	this->setState(new Indifferent());
}

void Citizen::setState(CitizenState* newState) {
	this->state = newState;
}

CitizenState* Citizen::getState() {
	return state;
}

void Citizen::notifyChange() {
	throw "Not yet implemented";
}

void Citizen::accept(TaxAndBudgetVisitor* visitor) {
	throw "Not yet implemented (needs other class to work)";
}

