#include "ServSecurity.h"

ServSecurity::ServSecurity() : Services(20)
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

ServSecurity::~ServSecurity()
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

void ServSecurity::displayBuildingInfo()
{
    cout << "Security service with " << this->visitors << " visitors\n";
}

int ServSecurity::getVisitors()
{
    return visitors;
}

void ServSecurity::setVisitors(int visitors)
{
    this->visitors = visitors;
}

void ServSecurity::callUtilities()
{
    notifyUtilities();
}

bool ServSecurity::getState()
{
    return operational;
}

void ServSecurity::setState(bool state)
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

std::string ServSecurity::getBuildingType()
{
    return type;
}

bool ServSecurity::addEmployee(Citizen *employee)
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

void ServSecurity::removeEmployee(Citizen *employee)
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


int ServSecurity::getElectricityUsage() {
    return electricityUsage;
}

int ServSecurity::getWaterUsage() {
    return waterUsage;
}

int ServSecurity::getCurCitizenCount() {
    return employees.size();
}
void ServSecurity::notifyEmployeeLeft(Citizen *employee)
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

bool ServSecurity::hasJob()
{
    return employees.size() < jobCapacity;
}
