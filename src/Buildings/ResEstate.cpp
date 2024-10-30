#include "ResEstate.h"

ResEstate::ResEstate() {
    cout << BLACK << "\t-->Estate created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addPopulation(popIncrease);
}

void ResEstate::displayBuildingInfo() {
    cout << "Estate for " << this->capacity << " people\n";
}

int ResEstate::getCapacity() const {
    return capacity;
}

void ResEstate::setCapacity(int capacity) {
    this->capacity = capacity;
}

void ResEstate::callUtilities(){
    notifyUtilities();
}

bool ResEstate::getState(){
    return operational;
}

void ResEstate::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string ResEstate::getBuildingType(){
    return type;
}