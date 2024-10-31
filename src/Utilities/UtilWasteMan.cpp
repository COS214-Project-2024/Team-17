#include "UtilWasteMan.h"
#include "../resources.h"
#include <iostream>
UtilWasteMan::UtilWasteMan() {
    std::cout << "Waste Dump Being Built!" << std::endl;
    type = "Waste Dump";
    operational = false; // constructing
    Resources::removeMoney(cost);
    Resources::removeWood(woodCost);
    Resources::removeSteel(steelCost);
    Resources::removeConcrete(concreteCost);
}



	void UtilWasteMan::startUtility(){
    std::cout << "Waste Dump Now available!" << std::endl;
    operational = true;
	}

	void UtilWasteMan::update(Building* unit){
    operational = unit->getState();
    if (operational==false) {
        startUtility();
        std::cout << "Waste Dump becoming available!" << std::endl;
    }
    }

	std::string UtilWasteMan::getType(){
        return type;
    }

	bool UtilWasteMan::isOperational(){
        return operational;
    }

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
