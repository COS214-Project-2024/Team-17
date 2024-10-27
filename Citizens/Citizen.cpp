#include "Citizen.h"
#include "CitizenNameGen.h"
#include <iostream>

Citizen::Citizen(CityMediator *mediator) : CityBlock(mediator)
{
	this->mediator = mediator;
	mediator->registerCitizen(this);
	setState(new Indifferent());
	name = CitizenNameGen::generateName();
}

void Citizen::setState(CitizenState *newState)
{
	if (newState == nullptr)
	{
		return;
	}
	std::cout << "Citizen " << name << " changed state to " << newState->getState() << std::endl;
	if (this->state != nullptr)
	{
		delete this->state;
	}
	this->state = newState;
}

CitizenState *Citizen::getState()
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

Citizen::~Citizen()
{
	if (state != nullptr)
	{
		delete state;
	}
}