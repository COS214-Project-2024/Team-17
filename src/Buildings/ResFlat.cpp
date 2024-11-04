#include "ResFlat.h"

ResFlat::ResFlat()
{
    cout << BLACK << "\t-->Flat created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addToMaxPopulation(popIncrease);
    setCapacity(popIncrease);
}

ResFlat::~ResFlat()
{
    cout << BLACK << "\t-->Flat destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeFromMaxPopulation(popIncrease);
    for (int i = 0; i < residents.size(); i++)
    {
        residents[i]->evicted();
    }
    residents.clear();
}

void ResFlat::displayBuildingInfo()
{
    cout << "Flat for " << this->capacity << " people\n";
}

int ResFlat::getCapacity() const
{
    return capacity;
}

void ResFlat::setCapacity(int capacity)
{
    this->capacity = 5;
}

void ResFlat::callUtilities()
{
    notifyUtilities();
}

bool ResFlat::getState()
{
    return operational;
}

void ResFlat::setState(bool state)
{
    if (operational != state)
    {
        operational = state;
        callUtilities();
    }
    else
    {
        cout << "No change in state" << endl;
    }
}

string ResFlat::getBuildingType()
{
    return type;
}

void ResFlat::notifyEmployeeLeft(Citizen *employee)
{
    for (int i = 0; i < residents.size(); i++)
    {
        if (residents[i] == employee)
        {
            residents.erase(residents.begin() + i);
        }
    }
}

bool ResFlat::moveIn(Citizen *resident)
{
    for (int i = 0; i < residents.size(); i++)
    {
        if (residents[i] == resident)
        {
            return false;
        }
    }

    if (residents.size() < capacity)
    {
        residents.push_back(resident);
        resident->setHome(this);
        return true;
    }
    return false;
}

void ResFlat::moveOut(Citizen *resident)
{
    for (int i = 0; i < residents.size(); i++)
    {
        if (residents[i] == resident)
        {
            residents.erase(residents.begin() + i);
            resident->evicted();
        }
    }
}

int ResFlat::getElectricityUsage()
{
    return electricityUsage;
}

int ResFlat::getWaterUsage()
{
    return waterUsage;
}

int ResFlat::getCurCitizenCount()
{
    return residents.size();
}