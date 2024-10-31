#include "LandMonument.h"

LandMonument::LandMonument() {
    cout << BLACK << "\t-->Monument created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happiness);
}

void LandMonument::displayBuildingInfo() {
    cout << "Monument with " << this->visitors << " visitors\n";
}

int LandMonument::getVisitors() {
    return visitors;
}

void LandMonument::setVisitors(int visitors) {
    this->visitors = visitors;
}

void LandMonument::callUtilities(){
    notifyUtilities();
}

bool LandMonument::getState(){
    return operational;
}

void LandMonument::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
            cout<<"No change in state"<<endl;
    }
}

string LandMonument::getBuildingType(){
    return type;
}

void LandMonument::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return;
    }
    employees.push_back(employee);
}

void LandMonument::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
} 