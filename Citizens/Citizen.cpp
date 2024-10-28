#include "Citizen.h"
#include "CitizenNameGen.h"
#include <iostream>

Citizen::Citizen(CityMediator *mediator) : CityBlock(mediator)
{
	this->mediator = mediator;
	mediator->registerCitizen(this);
	this->state = Indifferent();

	name = CitizenNameGen::generateName();
}

void Citizen::setState(CitizenState newState)
{
	this->state = newState;
}

CitizenState Citizen::getState()
{
	return state;
}

void Citizen::notifyChange(std::string message)
{
	std::cout << "Citizen " << name << " received message: " << message << std::endl;
}

void Citizen::accept(TaxAndBudgetVisitor *visitor)
{
	// TODO - implement Citizen::accept
	throw "Not yet implemented";
}

std::string Citizen::getName()
{
	return name;
}
