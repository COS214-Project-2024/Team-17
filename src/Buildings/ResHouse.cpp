#include "ResHouse.h"

ResHouse::ResHouse()
{
    cout << BLACK << "\t-->House created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addToMaxPopulation(popIncrease);
    setCapacity(popIncrease);
}

ResHouse::~ResHouse()
{
    cout << BLACK << "\t-->House destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeFromMaxPopulation(popIncrease);

    for (int i = 0; i < residents.size(); i++)
    {
        residents[i]->evicted();
    }
    residents.clear();
}

void ResHouse::displayBuildingInfo()
{
    cout << "House for " << this->capacity << " people\n";
}

int ResHouse::getCapacity() const
{
    return capacity;
}

void ResHouse::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void ResHouse::callUtilities()
{
    notifyUtilities();
}

bool ResHouse::getState()
{
    return operational;
}

void ResHouse::setState(bool state)
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

string ResHouse::getBuildingType()
{
    return type;
}

void ResHouse::notifyEmployeeLeft(Citizen *employee)
{
    std::cout << RED << "Resident left" << RESET << std::endl;
    for (int i = 0; i < residents.size(); i++)
    {
        if (residents[i] == employee)
        {
            residents.erase(residents.begin() + i);
        }
    }
}

bool ResHouse::moveIn(Citizen *resident)
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

void ResHouse::moveOut(Citizen *resident)
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

int ResHouse::getElectricityUsage()
{
    return electricityUsage;
}

int ResHouse::getWaterUsage()
{
    return waterUsage;
}

int ResHouse::getCurCitizenCount()
{
    return residents.size();
}