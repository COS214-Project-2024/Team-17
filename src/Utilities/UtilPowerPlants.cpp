#include "UtilPowerPlants.h"
#include "../resources.h"
#include <iostream>
/**
 * @brief Constructor for the UtilPowerPlants class.
 * Initializes the Power Plant utility as non-operational and sets the type.
 */
UtilPowerPlants::UtilPowerPlants() {
    std::cout << "Power Plant Being Built!" << std::endl;
    type = "Power Plant";
    operational = false; // constructing
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
}


/**
 * @brief Starts the Power Plant service and sets it to operational.
 */
	void UtilPowerPlants::startUtility(){
    std::cout << "Power Plant Now available!" << std::endl;
    operational = true;
	}

/**
 * @brief Updates the operational status of the Power Plant based on the building's status.
 * @param[in] unit Pointer to the Building object notifying this utility.
 * If the Power Plant is not operational, it will be started.
 */
	void UtilPowerPlants::update(Building* unit){
   //Or we can make the update print latest state of utility
    operational = unit->getState();
    if (operational==false) {
        
    std::cout << "Power Plant becoming available!" << std::endl;
    startUtility();
    }else{
		std::cout << "Power Plant is already operational!" << std::endl;
	}
    }

/**
 * @brief Gets the type of utility service provided by this class.
 * @return The type as a string, e.g., "Power Plant".
 */
	std::string UtilPowerPlants::getType(){
        return type;
    }

/**
 * @brief Checks if the Power Plant is operational.
 * @return True if the Power Plant is operational, false otherwise.
 */
	bool UtilPowerPlants::isOperational(){
        return operational;
    }

/**
 * @brief Shuts down the Power Plant service, setting it to non-operational.
 */
	void UtilPowerPlants::shutDown(){
        operational = false;
    std::cout << "Power Plant is now shut down!" << std::endl;
    }


// void UtilPowerPlants::generateElectricity(Building& building) {
// 	// TODO - implement UtilPowerPlants::generateElectricity
// 	throw "Not yet implemented";
// }



//Dont think the below is necessary!

// void UtilPowerPlants::addObserver(Building* observer) {
// 	// TODO - implement UtilPowerPlants::addObserver
// 	throw "Not yet implemented";
// }

// void UtilPowerPlants::removeObserver(Building* observer) {
// 	// TODO - implement UtilPowerPlants::removeObserver
// 	throw "Not yet implemented";
// }

// void UtilPowerPlants::notifyObservers() {
// 	// TODO - implement UtilPowerPlants::notifyObservers
// 	throw "Not yet implemented";
// }
