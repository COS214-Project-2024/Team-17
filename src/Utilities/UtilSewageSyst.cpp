#include "UtilSewageSyst.h"
#include "../resources.h"
#include <iostream>

/**
 * @brief Constructor for the UtilSewageSyst class.
 * Initializes the Sewage System utility as non-operational and sets the type.
 */
UtilSewageSyst::UtilSewageSyst() {
    std::cout << "Sewage System Being Built!" << std::endl;
    type = "Sewage System";
    operational = false; // constructing
//Recources:
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
}


/**
 * @brief Starts the Sewage System service and sets it to operational.
 */
	void UtilSewageSyst::startUtility(){
    std::cout << "Sewage System Now available!" << std::endl;
    operational = true;
	}

/**
 * @brief Updates the operational status of the Sewage System based on the building's status.
 * @param[in] unit Pointer to the Building object notifying this utility.
 * If the Sewage System is not operational, it will be started.
 */
	void UtilSewageSyst::update(Building* unit){
//Or we can make the update print latest state of utility
    operational = unit->getState();
    if (operational==false) {
        startUtility();
        std::cout << "Sewage System becoming available!" << std::endl;
    }else{
		std::cout << "Sewage System is already operational!" << std::endl;
	}
    }

/**
 * @brief Gets the type of utility service provided by this class.
 * @return The type as a string, e.g., "Sewage System".
 */
	std::string UtilSewageSyst::getType(){
        return type;
    }

/**
 * @brief Checks if the Sewage System is operational.
 * @return True if the Sewage System is operational, false otherwise.
 */
	bool UtilSewageSyst::isOperational(){
        return operational;
    }

/**
 * @brief Shuts down the Sewage System service, setting it to non-operational.
 */
	void UtilSewageSyst::shutDown(){
        operational = false;
    std::cout << "Sewage System is now shut down!" << std::endl;
    }
