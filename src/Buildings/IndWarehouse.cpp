#include "IndWarehouse.h"

IndWarehouse::IndWarehouse()
{
    cout << BLACK << "\t-->Warehouse created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addConcrete(concreteProduction);
}

IndWarehouse::~IndWarehouse()
{
    cout << BLACK << "\t-->Warehouse destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeWoodPerTick(concreteProduction);

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->fired();
    }

    employees.clear();
}

void IndWarehouse::displayBuildingInfo()
{
    cout << "Warehouse with production capacity of " << this->concreteProduction << " units\n";
}

int IndWarehouse::getProductionCapacity()
{
    return concreteProduction;
}

void IndWarehouse::setProductionCapacity(int capacity)
{
    this->concreteProduction = capacity;
}

void IndWarehouse::callUtilities()
{
    notifyUtilities();
}

bool IndWarehouse::getState()
{
    return operational;
}

void IndWarehouse::setState(bool state)
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

std::string IndWarehouse::getBuildingType()
{
    return type;
}

bool IndWarehouse::addEmployee(Citizen *employee)
{
    if (employees.size() >= jobCapacity)
    {
        cout << "Job capacity reached" << endl;
        return false;
    }

    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i] == employee)
        {
            cout << "Employee already works here" << endl;
            return false;
        }
    }

    employees.push_back(employee);
    employee->setWorkplace(this);
    return true;
}

void IndWarehouse::removeEmployee(Citizen *employee)
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

void IndWarehouse::notifyEmployeeLeft(Citizen *employee)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i] == employee)
        {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}

bool IndWarehouse::hasJob()
{
    return employees.size() < jobCapacity;
}
