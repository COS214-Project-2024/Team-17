#include "Building.h"
#include "../Citizens/CityCentralMediator.h"

// Observer Design Pattern
// Building::Building(CityMediator* mediator, string type) : CityBlock(mediator) {
// 	this->mediator = mediator;
// 	this->name = type;
// }

Building::Building(string type) : CityBlock()
{
    this->mediator = CityCentralMediator::getInstance();
    this->name = type;
}

string Building::getBuildingType()
{
    return name;
}

void Building::notifyChange(std::string message)
{
    mediator->notifyBuildingChange(this, message);
}

void Building::accept(TaxAndBudgetVisitor *visitor)
{
    // no clue  what this is
}

int Building::getXCordinate()
{
    return xCoordinate;
}

int Building::getYCordinate()
{
    return yCoordinate;
}

void Building::setXCordinate(int x)
{
    xCoordinate = x;
}

void Building::setYCordinate(int y)
{
    yCoordinate = y;
}
