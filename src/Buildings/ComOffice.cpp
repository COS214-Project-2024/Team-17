#include "ComOffice.h"

ComOffice::ComOffice() {
    cout << BLACK << "\t-->Office created" << RESET << endl;
    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addIncome(income);
}

void ComOffice::displayBuildingInfo() {
    cout << "Office with " << this->jobCapacity << " jobs\n";
}

int ComOffice::getJobCapacity() {
    return jobCapacity;
}

void ComOffice::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}

// Observer
void ComOffice::callUtilities(){
    notifyUtilities();
}

bool ComOffice::getState(){
    return operational;
}

void ComOffice::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else {
            cout<<"No change in state"<<endl;
    }
}

string ComOffice::getBuildingType(){
    return type;
}

void ComOffice::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return;
    }
    employees.push_back(employee);
}

void ComOffice::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}