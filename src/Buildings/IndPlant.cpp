#include "IndPlant.h"

IndPlant::IndPlant()
{
    cout << BLACK << "\t-->Plant created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addWoodPerTick(steelProduction);
}

IndPlant::~IndPlant()
{
    cout << BLACK << "\t-->Plant destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeWoodPerTick(steelProduction);

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->fired();
    }

    employees.clear();
}

void IndPlant::displayBuildingInfo()
{
    cout << "Plant with production capacity of " << this->steelProduction << " units\n";
}

int IndPlant::getProductionCapacity()
{
    return steelProduction;
}

void IndPlant::setProductionCapacity(int capacity)
{
    this->steelProduction = capacity;
}

void IndPlant::callUtilities()
{
    notifyUtilities();
}

bool IndPlant::getState()
{
    return operational;
}

void IndPlant::setState(bool state)
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

std::string IndPlant::getBuildingType()
{
    return type;
}

bool IndPlant::addEmployee(Citizen *employee)
{
    if (employees.size() >= jobCapacity)
    {
        cout << "Job capacity reached" << endl;
        return false;
    }

    employees.push_back(employee);
    employee->setWorkplace(this);
    return true;
}

void IndPlant::removeEmployee(Citizen *employee)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i] == employee)
        {
            employees.erase(employees.begin() + i);
            employee->fired();
            break;
        }
    }
}

bool IndPlant::hasJob()
{
    return employees.size() < jobCapacity;
}
