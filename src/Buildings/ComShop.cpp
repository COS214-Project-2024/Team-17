#include "ComShop.h"

ComShop::ComShop() {
    cout << BLACK << "\t-->Shop created" << RESET << endl;
    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addIncome(income);
}

ComShop::~ComShop() {
    cout << BLACK << "\t-->Shop destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeIncome(income);

    for (int i = 0; i < employees.size(); i++) {
        employees[i]->fired();
    }

    employees.clear();
}

void ComShop::displayBuildingInfo() {
    cout << "Shop with " << this->jobCapacity << " jobs\n";
}

int ComShop::getJobCapacity() {
    return jobCapacity;
}

void ComShop::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}

void ComShop::callUtilities(){
    notifyUtilities();
}

bool ComShop::getState(){
    return operational;
}

void ComShop::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

string ComShop::getBuildingType(){
    return type;
}

bool ComShop::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return false;
    }

    employees.push_back(employee);
    employee->setWorkplace(this);
    return true;
}

void ComShop::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            employee->fired();
            break;
        }
    }
}