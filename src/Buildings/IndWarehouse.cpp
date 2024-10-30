#include "IndWarehouse.h"

IndWarehouse::IndWarehouse() {
    cout << BLACK << "\t-->Warehouse created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addWoodPerTick(concreteProduction);
}

void IndWarehouse::displayBuildingInfo() {
    cout << "Warehouse with production capacity of " << this->concreteProduction << " units\n";
}

int IndWarehouse::getProductionCapacity() {
    return concreteProduction;
}

void IndWarehouse::setProductionCapacity(int capacity) {
    this->concreteProduction = capacity;
}

void IndWarehouse::callUtilities(){
    notifyUtilities();
}

bool IndWarehouse::getState(){
    return operational;
}

void IndWarehouse::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string IndWarehouse::getBuildingType(){
    return type;
}

void IndWarehouse::addEmployee(Citizen* employee) {
    if (employees.size() >= jobCapacity) {
        cout << "Job capacity reached" << endl;
        return;
    }
    employees.push_back(employee);
}

void IndWarehouse::removeEmployee(Citizen* employee) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}