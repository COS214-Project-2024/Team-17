#include "ResHouse.h"

ResHouse::ResHouse() {
    cout << BLACK << "\t-->House created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addToMaxPopulation(popIncrease);
}

ResHouse::~ResHouse() {
    cout << BLACK << "\t-->House destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeFromMaxPopulation(popIncrease);

}

void ResHouse::displayBuildingInfo() {
    cout << "House for " << this->capacity << " people\n";
}

int ResHouse::getCapacity() const {
    return capacity;
}

void ResHouse::setCapacity(int capacity) {
    this->capacity = capacity;
}

void ResHouse::callUtilities(){
    notifyUtilities();
}

bool ResHouse::getState(){
    return operational;
}

void ResHouse::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

string ResHouse::getBuildingType(){
    return type;
}