#include "IndPlant.h"

IndPlant::IndPlant() {
    cout << BLACK << "\t-->Plant created" << RESET << endl;

    Resources::removeMoney(woodCost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addWoodPerTick(steelProduction);
}

void IndPlant::displayBuildingInfo() {
    cout << "Plant with production capacity of " << this->steelProduction << " units\n";
}

int IndPlant::getProductionCapacity() {
    return steelProduction;
}

void IndPlant::setProductionCapacity(int capacity) {
    this->steelProduction = capacity;
}

void IndPlant::callUtilities(){
    notifyUtilities();
}

bool IndPlant::getState(){
    return operational;
}

void IndPlant::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string IndPlant::getBuildingType(){
    return type;
}