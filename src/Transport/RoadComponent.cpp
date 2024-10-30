#include "RoadComponent.h"
#include "../Citizens/CityMediator.h"
#include "../Citizens/CityCentralMediator.h"
#include "RoadIterator.h"
#include "RoadState.h"

RoadIterator *RoadComponent::createIterator()
{
	// TODO - implement RoadComponent::createIterator
	throw "Not yet implemented";
}

void RoadComponent::setState(RoadState *newState)
{
	if (this->state != nullptr)
	{
		delete this->state;
	}
	this->state = newState;
}

void RoadComponent::handleTraffic()
{
	// TODO - implement RoadComponent::handleTraffic
	throw "Not yet implemented";
}

RoadComponent::RoadComponent() : CityBlock()
{
	mediator = CityCentralMediator::getInstance();
	// TODO - implement RoadComponent::RoadComponent
	// throw "Not yet implemented";
}

// void RoadComponent::updateTraffic(TrafficStatus newStatus)
// {
// 	// TODO - implement RoadComponent::updateTraffic
// 	throw "Not yet implemented";
// }

void RoadComponent::notifyChange()
{
	// TODO - implement RoadComponent::notifyChange
	throw "Not yet implemented";
}

void RoadComponent::accept(TaxAndBudgetVisitor *visitor)
{
	// TODO - implement RoadComponent::accept
	throw "Not yet implemented";
}

RoadComponent::~RoadComponent()
{
	if (state != nullptr)
	{
		delete state;
	}
}
