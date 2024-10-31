#include "ServEducation.h"

ServEducation::ServEducation() {
    cout << BLACK << "\t-->Education service created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happinessIncrease);
    Resources::addIncome(cityIncome);
}

ServEducation::~ServEducation() {
    cout << BLACK << "\t-->Education service destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeHappiness(happinessIncrease);
    Resources::removeIncome(cityIncome);

    for (int i = 0; i < employees.size(); i++) {
        employees[i]->fired();
    }

    employees.clear();
}

void ServEducation::displayBuildingInfo() {
    cout << "Education service with " << this->visitors << " visitors\n";
}

int ServEducation::getVisitors() {
    return visitors;
}

void ServEducation::setVisitors(int visitors) {
    this->visitors = visitors;
}

void ServEducation::callUtilities(){
    notifyUtilities();
}

bool ServEducation::getState(){
    return operational;
}

void ServEducation::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

string ServEducation::getBuildingType(){
    return type;
}

bool ServEducation::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return false;
    }

    employees.push_back(employee);
    employee->setWorkplace(this);
    return true;
}

void ServEducation::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}