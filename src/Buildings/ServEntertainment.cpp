#include "ServEntertainment.h"

ServEntertainment::ServEntertainment() {
    cout << BLACK << "\t-->Entertainment service created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happinessIncrease);
    Resources::addIncome(cityIncome);
}

void ServEntertainment::displayBuildingInfo() {
    cout << "Entertainment service with " << this->visitors << " visitors\n";
}

int ServEntertainment::getVisitors() {
    return visitors;
}

void ServEntertainment::setVisitors(int visitors) {
    this->visitors = visitors;
}

void ServEntertainment::callUtilities(){
    notifyUtilities();
}

bool ServEntertainment::getState(){
        return operational;
}

void ServEntertainment::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

string ServEntertainment::getBuildingType(){
    return type;
}

void ServEntertainment::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return;
    }
    employees.push_back(employee);
}

void ServEntertainment::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}