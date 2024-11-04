#include "LandMonument.h"

LandMonument::LandMonument()
{
    cout << BLACK << "\t-->Monument created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happiness);
}

LandMonument::~LandMonument()
{
    cout << BLACK << "\t-->Monument destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeHappiness(happiness);

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->fired();
    }

    employees.clear();
}

void LandMonument::displayBuildingInfo()
{
    cout << "Monument with " << this->visitors << " visitors\n";
}

int LandMonument::getVisitors()
{
    return visitors;
}

void LandMonument::setVisitors(int visitors)
{
    this->visitors = visitors;
}

void LandMonument::callUtilities()
{
    notifyUtilities();
}

bool LandMonument::getState()
{
    return operational;
}

void LandMonument::setState(bool state)
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

string LandMonument::getBuildingType()
{
    return type;
}

bool LandMonument::addEmployee(Citizen *employee)
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

void LandMonument::removeEmployee(Citizen *employee)
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

void LandMonument::notifyEmployeeLeft(Citizen *employee)
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

bool LandMonument::hasJob()
{
    return employees.size() < jobCapacity;
}

int LandMonument::getElectricityUsage()
{
    return electricityUsage;
}

int LandMonument::getWaterUsage()
{
    return waterUsage;
}

int LandMonument::getCurCitizenCount()
{
    return employees.size();
}
