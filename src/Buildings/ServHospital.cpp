#include "ServHospital.h"
#include <iostream>
ServHospital::ServHospital() : Services(100)
{
    cout << BLACK << "\t-->Security service created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happinessIncrease);
    Resources::addIncome(cityIncome);
}

ServHospital::~ServHospital()
{
    cout << BLACK << "\t-->Security service destroyed" << RESET << endl;
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

void ServHospital::displayBuildingInfo()
{
    cout << "Security service with " << this->visitors << " visitors\n";
}

int ServHospital::getVisitors()
{
    return visitors;
}

void ServHospital::setVisitors(int visitors)
{
    this->visitors = visitors;
}

void ServHospital::callUtilities()
{
    notifyUtilities();
}

bool ServHospital::getState()
{
    return operational;
}

void ServHospital::setState(bool state)
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

std::string ServHospital::getBuildingType()
{
    return type;
}

bool ServHospital::addEmployee(Citizen *employee)
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

void ServHospital::removeEmployee(Citizen *employee)
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

int ServHospital::getElectricityUsage() {
    return electricityUsage;
}

int ServHospital::getWaterUsage() {
    return waterUsage;
}

int ServHospital::getCurCitizenCount() {
    return employees.size();
}
void ServHospital::notifyEmployeeLeft(Citizen *employee)
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

bool ServHospital::hasJob()
{
    return employees.size() < jobCapacity;
}
