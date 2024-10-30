#include "UtilSewageSyst.h"
#include <iostream>
UtilSewageSyst::UtilSewageSyst() {
    std::cout << "Sewage System Being Built!" << std::endl;
    type = "Sewage System";
    operational = false; // constructing
}



	void UtilSewageSyst::startUtility(){
    std::cout << "Sewage System Now available!" << std::endl;
    operational = true;
	}

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

	std::string UtilSewageSyst::getType(){
        return type;
    }

	bool UtilSewageSyst::isOperational(){
        return operational;
    }

	void UtilSewageSyst::shutDown(){
        operational = false;
    std::cout << "Sewage System is now shut down!" << std::endl;
    }
