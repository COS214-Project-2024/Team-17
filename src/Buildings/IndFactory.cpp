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