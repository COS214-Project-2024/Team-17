#include "ServHospital.h"
#include <iostream>
ServHospital::ServHospital() {
    cout << BLACK << "\t-->Security service created" << RESET << endl;
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
    Resources::addElectricityUsage(electricityUsage);
    Resources::addWaterUsage(waterUsage);
    Resources::addHappiness(happinessIncrease);
    /*
	int jobCapacity = 20;
	int cityIncome = 50;*/
}

void ServHospital::displayBuildingInfo() {
    cout << "Security service with " << this->visitors << " visitors\n";
}

int ServHospital::getVisitors() {
    return visitors;
}

void ServHospital::setVisitors(int visitors) {
    this->visitors = visitors;
}

void ServHospital::callUtilities(){
    notifyUtilities();
}

bool ServHospital::getState(){
    return operational;
}

void ServHospital::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string ServHospital::getBuildingType(){
    return type;
}