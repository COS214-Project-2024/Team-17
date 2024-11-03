#include "UtilWaterSupply.h"
#include "../resources.h"
#include <iostream>

/**
 * @brief Constructor for the UtilWaterSupply class.
 * Initializes the Water Supply utility as non-operational and sets the type.
 */
UtilWaterSupply::UtilWaterSupply() {
    std::cout << "Water Supply Being Built!" << std::endl;
    type = "Water Supply";
    operational = false; // constructing
//Recources:
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
}


/**
 * @brief Starts the Water Supply service and sets it to operational.
 */
	void UtilWaterSupply::startUtility(){
    std::cout << "Water Supply Now available!" << std::endl;
    operational = true;
    }

/**
 * @brief Updates the operational status of the Water Supply based on the building's status.
 * @param[in] unit Pointer to the Building object notifying this utility.
 * If the Water Supply is not operational, it will be started.
 */
	void UtilWaterSupply::update(Building* unit){
    operational = unit->getState();
    if (operational==false) {
        startUtility();
        std::cout << "Water Supply becoming available!" << std::endl;
    }
    }

/**
 * @brief Gets the type of utility service provided by this class.
 * @return The type as a string, e.g., "Water Supply".
 */
	std::string UtilWaterSupply::getType(){
        return type;
    }

/**
 * @brief Checks if the Water Supply is operational.
 * @return True if the Water Supply is operational, false otherwise.
 */
	bool UtilWaterSupply::isOperational(){
        return operational;
    }

/**
 * @brief Shuts down the Water Supply service, setting it to non-operational.
 */
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