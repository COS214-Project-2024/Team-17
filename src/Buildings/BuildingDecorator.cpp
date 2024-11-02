#include "BuildingDecorator.h"

BuildingDecorator::BuildingDecorator(Building *b) : Building()
{
    building = b;
}

void BuildingDecorator::displayBuildingInfo()
{
    if (building)
    {
        building->displayBuildingInfo();
    }
}

BuildingDecorator::~BuildingDecorator()
{
    delete building;
}

bool BuildingDecorator::checkBuildRequirements()
{
    return building->checkBuildRequirements();
}

bool BuildingDecorator::getState()
{
    return building->getState();
}

bool BuildingDecorator::addEmployee(Citizen *employee)
{
    return building->addEmployee(employee);
}

void BuildingDecorator::removeEmployee(Citizen *employee)
{
    building->removeEmployee(employee);
}

bool BuildingDecorator::moveIn(Citizen *resident)
{
    return building->moveIn(resident);
}

void BuildingDecorator::moveOut(Citizen *resident)
{
    building->moveOut(resident);
}
