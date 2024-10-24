#include "RoadComponent.h"
#include "../Citizens/CityMediator.h"

RoadIterator *RoadComponent::createIterator()
{
	// TODO - implement RoadComponent::createIterator
	throw "Not yet implemented";
}

void RoadComponent::setState(RoadState *newState)
{
	this->state = newState;
}

void RoadComponent::handleTraffic()
{
	// TODO - implement RoadComponent::handleTraffic
	throw "Not yet implemented";
}

RoadComponent::RoadComponent(CityMediator *mediator) : CityBlock(mediator)
{
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
