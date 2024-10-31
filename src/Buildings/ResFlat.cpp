#include "ResFlat.h"

ResFlat::ResFlat() {
    cout << BLACK << "\t-->Flat created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addToMaxPopulation(popIncrease);
}

ResFlat::~ResFlat() {
    cout << BLACK << "\t-->Flat destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeFromMaxPopulation(popIncrease);
}

void ResFlat::displayBuildingInfo() {
    cout << "Flat for " << this->capacity << " people\n";
}

int ResFlat::getCapacity() const {
    return capacity;
}

void ResFlat::setCapacity(int capacity) {
    this->capacity = capacity;
}

void ResFlat::callUtilities(){
    notifyUtilities();
}

bool ResFlat::getState(){
    return operational;
}

void ResFlat::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

string ResFlat::getBuildingType(){
    return type;
}