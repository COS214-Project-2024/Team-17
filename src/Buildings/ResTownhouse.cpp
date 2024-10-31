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

    for (int i = 0; i < residents.size(); i++) {
        residents[i]->evicted();
    }
    residents.clear();
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

bool ResTownhouse::moveIn(Citizen* resident) {
    if (residents.size() < capacity) {
        residents.push_back(resident);
        return true;
    }
    return false;
}

void ResTownhouse::moveOut(Citizen* resident) {
    for (int i = 0; i < residents.size(); i++) {
        if (residents[i] == resident) {
            residents.erase(residents.begin() + i);
        }
    }
}