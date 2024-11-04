#include "ComMall.h"
/**
 * @class ComMall
 * @brief Represents a commercial mall building with specific resource requirements, utility usage, and job management.
 *
 * This class manages resources upon construction and destruction, maintains a list of employees, 
 * and interacts with utility services when its operational state changes.
 */

ComMall::ComMall()
{
    cout << BLACK << "\t-->Mall created" << RESET << endl;
    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addIncome(income);
}

ComMall::~ComMall()
{
    cout << BLACK << "\t-->Mall destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeIncome(income);

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i]->fired();
    }

    employees.clear();
}

void ComMall::displayBuildingInfo()
{
    cout << "Mall with " << this->jobCapacity << " jobs\n";
}

int ComMall::getJobCapacity()
{
    return jobCapacity;
}

void ComMall::setJobCapacity(int capacity)
{
    this->jobCapacity = capacity;
}

// Observer
void ComMall::callUtilities()
{
    notifyUtilities();
}

bool ComMall::getState()
{
    return operational;
}

void ComMall::setState(bool state)
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

string ComMall::getBuildingType()
{
    return type;
}

bool ComMall::addEmployee(Citizen *employee)
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

void ComMall::removeEmployee(Citizen *employee)
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

void ComMall::notifyEmployeeLeft(Citizen *employee)
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

bool ComMall::hasJob()
{
    return employees.size() < jobCapacity;
}
