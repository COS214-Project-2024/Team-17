#include "ResTownhouse.h"

ResTownhouse::ResTownhouse() {
    cout << BLACK << "\t-->Townhouse created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addToMaxPopulation(popIncrease);
}

ResTownhouse::~ResTownhouse() {
    cout << BLACK << "\t-->Townhouse destroyed" << RESET << endl;
    Resources::removeElectricityUsage(electricityUsage);
    Resources::removeWaterUsage(waterUsage);
    Resources::removeFromMaxPopulation(popIncrease);
}

void ResTownhouse::displayBuildingInfo() {
    cout << "Townhouse for " << this->capacity << " people\n";
}

int ResTownhouse::getCapacity() const {
    return capacity;
}

void ResTownhouse::setCapacity(int capacity) {
    this->capacity = capacity;
}

void ResTownhouse::callUtilities(){
    notifyUtilities();
}

bool ResTownhouse::getState(){
    return operational;
}

void ResTownhouse::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string ResTownhouse::getBuildingType(){
    return type;
}