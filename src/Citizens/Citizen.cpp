#include "Citizen.h"
#include "CitizenNameGen.h"
#include "CityCentralMediator.h"
#include <iostream>

Citizen::Citizen() : CityBlock()
{
	this->mediator = CityCentralMediator::getInstance();
	mediator->registerCitizen(this);
	setState(new Indifferent());
	// name = CitizenNameGen::generateName();
	name = "John Doe";
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

void Citizen::setWorkplace(Building *workplace)
{
	this->workplace = workplace;
}

Building *Citizen::getWorkplace()
{
	return workplace;
}

void Citizen::fired()
{
	workplace = nullptr;
	std::cout << "Citizen " << name << " was fired" << std::endl;
}

void Citizen::setHome(Building *home)
{
	this->home = home;
}

Building *Citizen::getHome()
{
	return home;
}

void Citizen::evicted()
{
	home = nullptr;
	std::cout << "Citizen " << name << " was evicted" << std::endl;
}


Citizen::~Citizen()
{
	if (state != nullptr)
	{
		delete state;
	}
}
