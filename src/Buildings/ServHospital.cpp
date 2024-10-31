#include "ServHospital.h"
#include <iostream>
ServHospital::ServHospital() {
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

void ServHospital::displayBuildingInfo() {
    cout << "Security service with " << this->visitors << " visitors\n";
}

int ServHospital::getVisitors() {
    return visitors;
}

void ServHospital::setVisitors(int visitors) {
    this->visitors = visitors;
}

void ServHospital::callUtilities(){
    notifyUtilities();
}

bool ServHospital::getState(){
    return operational;
}

void ServHospital::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string ServHospital::getBuildingType(){
    return type;
}


void ServHospital::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return;
    }
    employees.push_back(employee);
}

void ServHospital::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}