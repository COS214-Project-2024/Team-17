#include "UtilWasteMan.h"
#include "../resources.h"
#include <iostream>

/**
 * @brief Constructor for the UtilWasteMan class.
 * Initializes the Waste Dump utility as non-operational and sets the type.
 */
UtilWasteMan::UtilWasteMan() {
    std::cout << "Waste Dump Being Built!" << std::endl;
    type = "Waste Dump";
    operational = false; // constructing
//Recources:
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
}


/**
 * @brief Starts the Waste Dump service and sets it to operational.
 */
	void UtilWasteMan::startUtility(){
    std::cout << "Waste Dump Now available!" << std::endl;
    operational = true;
	}

/**
 * @brief Updates the operational status of the Waste Dump based on the building's status.
 * @param[in] unit Pointer to the Building object notifying this utility.
 * If the Waste Dump is not operational, it will be started.
 */
	void UtilWasteMan::update(Building* unit){
    operational = unit->getState();
    if (operational==false) {
        startUtility();
        std::cout << "Waste Dump becoming available!" << std::endl;
    }
    }

/**
 * @brief Gets the type of utility service provided by this class.
 * @return The type as a string, e.g., "Waste Dump".
 */
	std::string UtilWasteMan::getType(){
        return type;
    }

/**
 * @brief Checks if the Waste Dump is operational.
 * @return True if the Waste Dump is operational, false otherwise.
 */
	bool UtilWasteMan::isOperational(){
        return operational;
    }

/**
 * @brief Shuts down the Waste Dump service, setting it to non-operational.
 */
	void UtilWasteMan::shutDown(){
        operational = false;
    std::cout << "Waste Dump is now shut down!" << std::endl;
    }

// void UtilWasteMan::checkWasteSupply() {
// 	if(operational==1){
// 		cout<<"Wate supply is Operational"<<endl;
// 	}else if(operational==0){
// 		cout<<"Waste supply Inoperable"<<endl;
// 	}
	
// }

// void UtilWasteMan::setState(string state){
// 		this->operational=operational;
// 		checkWasteSupply();
// 		notifyDevices();
// 	}

// bool UtilWasteMan::getState(){
// 	return operational;
// }

// void UtilWasteMan::notifysensor(){
// 	notifyDevices();
// }
