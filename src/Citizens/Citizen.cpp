#include "Citizen.h"
#include "CitizenNameGen.h"
#include "CityCentralMediator.h"
#include "../resources.h"
#include <iostream>
#include "../../colours.h"
#include "../Buildings/Building.h"
#include "../Transport/RoadComponent.h"
#include "Bus.h"

void Citizen::changeHappiness(int change)
{
	CitizenState *newState = state->handleChange(change);
	setState(newState);
}

Citizen::Citizen(bool autoRegister) : CityBlock()
{
	name = "John Doe";
	this->mediator = CityCentralMediator::getInstance();
	if (autoRegister)
	{
		mediator->registerCitizen(this);
	}
	state = nullptr;
	setState(new Indifferent());
	name = CitizenNameGen::generateName();
	Resources::addPopulation(1);
	activity = Activity::Nothing;
	currentLocation = nullptr;
	currentRoad = nullptr;
	myBus = nullptr;
	ownsCar = false;
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
	if (message == "Go_Home")
	{
		std::cout << YELLOW << "Citizen " << name << " is going home" << RESET << std::endl;
		if (!ownsCar)
		{
			CityCentralMediator *ccm = dynamic_cast<CityCentralMediator *>(mediator);
			Trainstation *workStation = ccm->trainstationInRange(workplace->getXCoordinate(), workplace->getYCoordinate());
			Trainstation *homeStation = ccm->trainstationInRange(home->getXCoordinate(), home->getYCoordinate());
			if (workStation && homeStation)
			{
				std::cout << "Citizen " << name << " took the train home" << std::endl;
				activity = Activity::Rest;
				currentLocation = home;
			}
			else
			{
				waitTimer = 3;
				activity = Activity::TryBusHome;
			}
		}
	}
	else if (message == "Go_Work")
	{
		std::cout << YELLOW << "Citizen " << name << " is going to work" << RESET << std::endl;
		if (!ownsCar)
		{
			CityCentralMediator *ccm = dynamic_cast<CityCentralMediator *>(mediator);
			Trainstation *workStation = ccm->trainstationInRange(workplace->getXCoordinate(), workplace->getYCoordinate());
			Trainstation *homeStation = ccm->trainstationInRange(home->getXCoordinate(), home->getYCoordinate());
			if (workStation && homeStation)
			{
				std::cout << "Citizen " << name << " took the train to work" << std::endl;
				activity = Activity::Work;
				currentLocation = workplace;
			}
			else
			{
				waitTimer = 3;
				activity = Activity::TryBusWork;
			}
		}
	}
	else if (message == "Arrived_Destination")
	{
		std::cout << YELLOW << "Citizen " << name << " arrived at destination" << RESET << std::endl;
		if (activity == Activity::InTransitWork)
		{
			activity = Activity::Work;
			currentLocation = workplace;
		}
		else if (activity == Activity::InTransitHome)
		{
			activity = Activity::Rest;
			currentLocation = home;
		}
		myBus = nullptr;
	}
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
	this->currentLocation = workplace;
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
	this->currentLocation = home;
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

void Citizen::giveCar()
{
	ownsCar = true;
	std::cout << "Citizen " << name << " was given a car" << std::endl;
}

void Citizen::doSomething()
{
	CityCentralMediator *ccm = dynamic_cast<CityCentralMediator *>(mediator);

	switch (activity)
	{
	case Activity::Rest:
		std::cout << "Citizen " << name << " is resting" << std::endl;
		break;
	case Activity::Work:
		std::cout << "Citizen " << name << " is working" << std::endl;
		break;
	case Activity::InTransitWork:
		std::cout << "Citizen " << name << " is in transit to work" << std::endl;
		break;
	case Activity::AwaitTransitWork:
		std::cout << "Citizen " << name << " is awaiting transit to work" << std::endl;
		if (myBus->getCurrentLocation() == currentRoad)
		{
			activity = Activity::InTransitWork;
			currentLocation = nullptr;
			myBus->addPassenger(this, ccm->getClosestRoad(workplace->getXCoordinate(), workplace->getYCoordinate()));
		}
		break;
	case Activity::InTransitHome:
		std::cout << "Citizen " << name << " is in transit home" << std::endl;
		break;
	case Activity::AwaitTransitHome:
		std::cout << "Citizen " << name << " is awaiting transit home" << std::endl;
		if (myBus->getCurrentLocation() == currentRoad)
		{
			activity = Activity::InTransitHome;
			currentLocation = nullptr;
			myBus->addPassenger(this, ccm->getClosestRoad(home->getXCoordinate(), home->getYCoordinate()));
		}
		break;
	case Activity::Nothing:
		std::cout << "Citizen " << name << " is doing nothing" << std::endl;
		break;
	case Activity::TryBusWork:
		currentRoad = ccm->getClosestRoad(currentLocation->getXCoordinate(), currentLocation->getYCoordinate());
		if (currentRoad)
		{
			for (auto c : currentRoad->getUsers())
			{
				Bus *bus = dynamic_cast<Bus *>(c);
				if (bus)
				{
					if (!bus->isFull())
					{
						std::cout << "Found bus" << std::endl;
						myBus = bus;
						activity = Activity::InTransitWork;
						currentLocation = nullptr;
						myBus->addPassenger(this, ccm->getClosestRoad(workplace->getXCoordinate(), workplace->getYCoordinate()));
						break;
					}
				}
			}
		}
		if (waitTimer > 0)
		{
			std::cout << RED << "Waiting for bus" << RESET << std::endl;
			waitTimer--;
			break;
		}
		currentRoad = ccm->getClosestRoad(currentLocation->getXCoordinate(), currentLocation->getYCoordinate());
		if (currentRoad)
		{
			myBus = ccm->requestBus(nullptr, currentRoad);
			if (myBus)
			{
				activity = Activity::AwaitTransitWork;
			}
			else
			{
				std::cout << RED << "Trying to wait for another bus!" << RESET << std::endl;
				activity = Activity::TryBusWork;
				waitTimer = 3;
			}
		}
		else
		{
			std::cout << RED << "Could not find closest road for citizen!" << RESET << std::endl;
		}
		break;
	case Activity::TryBusHome:
		currentRoad = ccm->getClosestRoad(currentLocation->getXCoordinate(), currentLocation->getYCoordinate());
		if (currentRoad)
		{
			for (Citizen *c : currentRoad->getUsers())
			{
				std::cout << c->getName() << std::endl;

				Bus *bus = dynamic_cast<Bus *>(c);
				if (bus)
				{
					if (!bus->isFull())
					{
						std::cout << "Found bus" << std::endl;
						myBus = bus;
						activity = Activity::InTransitHome;
						currentLocation = nullptr;
						myBus->addPassenger(this, ccm->getClosestRoad(home->getXCoordinate(), home->getYCoordinate()));
						break;
					}
				}
			}
		}
		if (waitTimer > 0)
		{
			std::cout << RED << "Waiting for bus" << RESET << std::endl;
			waitTimer--;
			break;
		}
		currentRoad = ccm->getClosestRoad(currentLocation->getXCoordinate(), currentLocation->getYCoordinate());
		if (currentRoad)
		{
			myBus = ccm->requestBus(nullptr, currentRoad);
			if (myBus)
			{
				activity = Activity::AwaitTransitHome;
			}
			else
			{
				std::cout << RED << "Trying to wait for another bus!" << RESET << std::endl;
				activity = Activity::TryBusWork;
				waitTimer = 3;
			}
		}
		else
		{
			std::cout << RED << "Could not find closest road for citizen!" << RESET << std::endl;
		}
		break;
	}
}

Building *Citizen::getCurrentBuilding()
{
	return currentLocation;
}

int Citizen::getHappiness()
{
	std::string stat = state->getState();

	if (stat == "Happy")
	{
		return 100;
	}
	else if (stat == "Content")
	{
		return 75;
	}
	else if (stat == "Indifferent")
	{
		return 50;
	}
	else if (stat == "Discontent")
	{
		return 25;
	}
	else if (stat == "Upset")
	{
		return 0;
	}
}

Citizen::~Citizen()
{
	std::cout << "Citizen " << name << " deleted" << std::endl;
}
