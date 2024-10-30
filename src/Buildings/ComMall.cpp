#include "ComMall.h"

ComMall::ComMall() {
    cout << BLACK << "\t-->Mall created" << RESET << endl;
    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addIncome(income);
}

void ComMall::displayBuildingInfo() {
    cout << "Mall with " << this->jobCapacity << " jobs\n";
}

int ComMall::getJobCapacity() {
    return jobCapacity;
}

void ComMall::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}

// Observer
void ComMall::callUtilities() {
    notifyUtilities();
}

bool ComMall::getState() {
    return operational;
}

void ComMall::setState(bool state) {
    if (operational != state) {
        operational = state;
        callUtilities();
    } else {
        cout << "No change in state" << endl;
    }
}

void ComMall::addEmployee(Citizen* employee) {
    employees.push_back(employee);
}

void ComMall::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}

string ComMall::getBuildingType() {
    return type;
}