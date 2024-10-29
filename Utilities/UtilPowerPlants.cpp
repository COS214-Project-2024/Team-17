#include "UtilPowerPlants.h"
#include <iostream>
UtilPowerPlants::UtilPowerPlants() {
    std::cout << "Power Plant Being Built!" << std::endl;
    type = "Power Plant";
    operational = false; // constructing
}



	void UtilPowerPlants::startUtility(){
    std::cout << "Power Plant Now available!" << std::endl;
    operational = true;
	}

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

	std::string UtilPowerPlants::getType(){
        return type;
    }

	bool UtilPowerPlants::isOperational(){
        return operational;
    }

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
