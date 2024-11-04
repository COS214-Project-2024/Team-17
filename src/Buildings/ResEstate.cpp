#include "ResEstate.h"

ResEstate::ResEstate()
{
    cout << BLACK << "\t-->Estate created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addToMaxPopulation(popIncrease);
    setCapacity(popIncrease);
}

ResEstate::~ResEstate()
{
    cout << BLACK << "\t-->Estate destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeFromMaxPopulation(popIncrease);
    for (int i = 0; i < residents.size(); i++)
    {
        residents[i]->evicted();
    }
    residents.clear();
}

void ResEstate::displayBuildingInfo()
{
    cout << "Estate for " << this->capacity << " people\n";
}

int ResEstate::getCapacity() const
{
    return capacity;
}

void ResEstate::setCapacity(int capacity)
{
    this->capacity = 50;
}

void ResEstate::callUtilities()
{
    notifyUtilities();
}

bool ResEstate::getState()
{
    return operational;
}

void ResEstate::setState(bool state)
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

std::string ResEstate::getBuildingType()
{
    return type;
}

void ResEstate::notifyEmployeeLeft(Citizen *employee)
{
    for (int i = 0; i < residents.size(); i++)
    {
        if (residents[i] == employee)
        {
            residents.erase(residents.begin() + i);
        }
    }
}

bool ResEstate::moveIn(Citizen *resident)
{
    // check if if the resident is already in the estate
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

void ResEstate::moveOut(Citizen *resident)
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

int ResEstate::getElectricityUsage()
{
    return electricityUsage;
}

int ResEstate::getWaterUsage()
{
    return waterUsage;
}

int ResEstate::getCurCitizenCount()
{
    return residents.size();
}