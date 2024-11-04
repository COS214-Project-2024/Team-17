#include "ServEntertainment.h"

ServEntertainment::ServEntertainment() : Services(35)
{
    cout << BLACK << "\t-->Entertainment service created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happinessIncrease);
    Resources::addIncome(cityIncome);
}

ServEntertainment::~ServEntertainment()
{
    cout << BLACK << "\t-->Entertainment service destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeHappiness(happinessIncrease);
    Resources::removeIncome(cityIncome);

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->fired();
    }

    employees.clear();
}

void ServEntertainment::displayBuildingInfo()
{
    cout << "Entertainment service with " << this->visitors << " visitors\n";
}

int ServEntertainment::getVisitors()
{
    return visitors;
}

void ServEntertainment::setVisitors(int visitors)
{
    this->visitors = visitors;
}

void ServEntertainment::callUtilities()
{
    notifyUtilities();
}

bool ServEntertainment::getState()
{
    return operational;
}

void ServEntertainment::setState(bool state)
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

string ServEntertainment::getBuildingType()
{
    return type;
}

bool ServEntertainment::addEmployee(Citizen *employee)
{
    if (employees.size() >= jobCapacity)
    {
        cout << "Job capacity reached" << endl;
        return false;
    }

    // check if employee already works here
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

void ServEntertainment::removeEmployee(Citizen *employee)
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

void ServEntertainment::notifyEmployeeLeft(Citizen *employee)
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

bool ServEntertainment::hasJob()
{
    return employees.size() < jobCapacity;
}

int ServEntertainment::getElectricityUsage()
{
    return electricityUsage;
}

int ServEntertainment::getWaterUsage()
{
    return waterUsage;
}

int ServEntertainment::getCurCitizenCount()
{
    return employees.size();
}