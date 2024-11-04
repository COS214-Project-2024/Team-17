#include "ComOffice.h"

/**
 * @class ComOffice
 * @brief Represents a commercial office building with specific resource requirements, utility usage, and job management.
 *
 * This class handles resource management upon construction and destruction, maintains a list of employees, 
 * and interacts with utility services when its operational state changes.
 */
ComOffice::ComOffice()
{
    cout << BLACK << "\t-->Office created" << RESET << endl;
    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addIncome(income);
}

ComOffice::~ComOffice()
{
    cout << BLACK << "\t-->Office destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeIncome(income);

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->fired();
    }

    employees.clear();
}

void ComOffice::displayBuildingInfo()
{
    cout << "Office with " << this->jobCapacity << " jobs\n";
}

int ComOffice::getJobCapacity()
{
    return jobCapacity;
}

void ComOffice::setJobCapacity(int capacity)
{
    this->jobCapacity = capacity;
}

// Observer
void ComOffice::callUtilities()
{
    notifyUtilities();
}

bool ComOffice::getState()
{
    return operational;
}

void ComOffice::setState(bool state)
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

string ComOffice::getBuildingType()
{
    return type;
}

bool ComOffice::addEmployee(Citizen *employee)
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

void ComOffice::removeEmployee(Citizen *employee)
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

void ComOffice::notifyEmployeeLeft(Citizen *employee)
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

bool ComOffice::hasJob()
{
    return employees.size() < jobCapacity;
}
