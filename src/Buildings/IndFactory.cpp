#include "IndFactory.h"

IndFactory::IndFactory() {
    cout << BLACK << "\t-->Factory created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addWoodPerTick(woodProduction);
}

IndFactory::~IndFactory() {
    cout << BLACK << "\t-->Factory destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeWoodPerTick(woodProduction);

    for (int i = 0; i < employees.size(); i++) {
        employees[i]->fired();
    }

    employees.clear();
}

void IndFactory::displayBuildingInfo() {
    cout << "Factory with wood production capacity of " << this->woodProduction << " units\n";
}

int IndFactory::getProductionCapacity() {
    return woodProduction;
}

void IndFactory::setProductionCapacity(int capacity) {
    this->woodProduction = capacity;
}

void IndFactory::callUtilities(){
    notifyUtilities();
}

bool IndFactory::getState(){
    return operational;
}

void IndFactory::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string IndFactory::getBuildingType(){
    return type;
}


bool IndFactory::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return false;
    }

    employees.push_back(employee);
    employee->setWorkplace(this);
    return true;
}

void IndFactory::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            employee->fired();
            break;
        }
    }
}

int IndFactory::getElectricityUsage() {
    return electricityUsage;
}

int IndFactory::getWaterUsage() {
    return waterUsage;
}

int IndFactory::getCurCitizenCount() {
    return employees.size();
}