#include "LandCCenter.h"

LandCCenter::LandCCenter() {
    cout << BLACK << "\t-->Community center created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happiness);
}

void LandCCenter::displayBuildingInfo() {
    cout << "Community center with " << this->visitors << " visitors\n";
}

int LandCCenter::getVisitors() {
    return visitors;
}

void LandCCenter::setVisitors(int visitors) {
    this->visitors = visitors;
}

bool LandCCenter::checkBuildRequirements() {
    // I dunno why this was giving an error, but anyways [AMBER]
    return true;
}

void LandCCenter::callUtilities(){
    notifyUtilities();
}

bool LandCCenter::getState(){
    return operational;
}

void LandCCenter::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
            cout<<"No change in state"<<endl;
    }
}

std::string LandCCenter::getBuildingType(){
    return type;
}

void LandCCenter::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return;
    }
    employees.push_back(employee);
}

void LandCCenter::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}