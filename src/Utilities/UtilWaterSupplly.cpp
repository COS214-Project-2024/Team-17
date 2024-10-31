#include "UtilWaterSupply.h"
#include "../resources.h"
#include <iostream>

UtilWaterSupply::UtilWaterSupply() {
    std::cout << "Water Supply Being Built!" << std::endl;
    type = "Water Supply";
    operational = false; // constructing
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
}



	void UtilWaterSupply::startUtility(){
    std::cout << "Water Supply Now available!" << std::endl;
    operational = true;
    }

	void UtilWaterSupply::update(Building* unit){
    operational = unit->getState();
    if (operational==false) {
        startUtility();
        std::cout << "Water Supply becoming available!" << std::endl;
    }
    }

	std::string UtilWaterSupply::getType(){
        return type;
    }

	bool UtilWaterSupply::isOperational(){
        return operational;
    }

	void UtilWaterSupply::shutDown(){
        operational = false;
    std::cout << "Water Supply is now shut down!" << std::endl;
    }



    // // UtilityManager abstract methods
    // bool UtilWaterSupply::getState()  { return operational; }
    // void UtilWaterSupply::addObserver(Building* observer)  {
    //     addDevice(observer);
    //     cout << "Observer added to Water Supply" << endl;
    // }
    // void UtilWaterSupply::removeObserver(Building* observer)  {
    //     removeDevice(observer);
    //     cout << "Observer removed from Water Supply" << endl;
    // }
    // void UtilWaterSupply::notifyObservers()  {
    //     notifyDevices();
    //     cout << "Notifying all buildings from Water Supply" << endl;
    // }

    // void UtilWaterSupply::setState(string state) {
    //     operational = (state == "Operational");
    //     notifyObservers();
    // }
    
    // void UtilWaterSupply::checkWaterSupply() {
    //     cout << "Water supply is " << (operational ? "Operational" : "Inoperable") << endl;
    // }