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

void LandPark::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return;
    }
    employees.push_back(employee);
}

void LandPark::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
} 