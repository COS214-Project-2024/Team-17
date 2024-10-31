#include "LandPark.h"

LandPark::LandPark() {
    cout << BLACK << "\t-->Park created" << RESET << endl;
    
    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happiness);
}

LandPark::~LandPark() {
    cout << BLACK << "\t-->Park destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeHappiness(happiness);

    for (int i = 0; i < employees.size(); i++) {
        employees[i]->fired();
    }

    employees.clear();
}

void LandPark::displayBuildingInfo() {
    cout << "Park with " << this->visitors << " visitors\n";
}

int LandPark::getVisitors() {
    return visitors;
}

void LandPark::setVisitors(int visitors) {
    this->visitors = visitors;
}

void LandPark::callUtilities(){
    notifyUtilities();
}

bool LandPark::getState(){
    return operational;
}

void LandPark::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

string LandPark::getBuildingType(){
    return type;
}

bool LandPark::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return false;
    }

    employees.push_back(employee);
    employee->setWorkplace(this);
    return true;
}

void LandPark::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}