#include "Trainstation.h"
#include <cmath>
#include "../Citizens/CityCentralMediator.h"

Trainstation::Trainstation(int range) : Building("Trainstation")
{
    cout << BLACK << "\t-->Trainstation created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addToMaxPopulation(popIncrease);
    serveRange = range;
    CityCentralMediator::getInstance()->registerTrainStation(this);
}

void Trainstation::displayBuildingInfo()
{
    cout << "Trainstation\n";
}

Trainstation::~Trainstation()
{
}

bool Trainstation::getState()
{
    return operational;
}

string Trainstation::getBuildingType()
{
    return "Trainstation";
}

bool Trainstation::buildingInRange(Building *building)
{
    float distance = sqrt(pow(getXCoordinate() - building->getXCoordinate(), 2) + pow(getYCoordinate() - building->getYCoordinate(), 2));

    return distance <= serveRange;
}

bool Trainstation::pointInRange(int x, int y)
{
    float distance = sqrt(pow(getXCoordinate() - x, 2) + pow(getYCoordinate() - y, 2));
    return distance <= serveRange;
}

bool Trainstation::checkBuildRequirements()
{
    return true;
}

bool Trainstation::addEmployee(Citizen *employee)
{
    return true;
}

void Trainstation::removeEmployee(Citizen *employee)
{
}

void Trainstation::notifyEmployeeLeft(Citizen *employee)
{
}

bool Trainstation::hasJob()
{
    return false;
}

bool Trainstation::moveIn(Citizen *resident)
{
    return true;
}

void Trainstation::moveOut(Citizen *resident)
{
}
