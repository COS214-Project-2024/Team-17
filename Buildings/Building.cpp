#include "Building.h"

// Observer Design Pattern
     void Building::addUtility(UtilityManager* utility) {
    	Utilities.push_back(utility);
		std::cout<<this->getBuildingType()<<" Has Utility Connection of type:"<<utility->getType()<<std::endl;
		
    }
    
    void Building::removeUtility(UtilityManager* utility) {
    auto it = Utilities.begin();
    while (it != Utilities.end()) {
        if (*it == utility) {
            Utilities.erase(it);
			std::cout<<"Utility Deconstruction of type:"<<utility->getType()<<std::endl;
            return;
        }
        ++it;
    }
}

	void Building::notifyUtilities(){
  for(UtilityManager* utility:Utilities){
	  utility->update(this);
  }
	}

// void Building::receiveElectricity() {
// 	// TODO - implement Building::receiveElectricity
// 	throw "Not yet implemented";
// }

// void Building::receiveWater() {
// 	// TODO - implement Building::receiveWater
// 	throw "Not yet implemented";
// }

// void Building::removeWaste() {
// 	// TODO - implement Building::removeWaste
// 	throw "Not yet implemented";
// }

// void Building::removeSewage() {
// 	// TODO - implement Building::removeSewage
// 	throw "Not yet implemented";
// }

// void Building::notifyOutage(string& utility) {
// 	// TODO - implement Building::notifyOutage
// 	throw "Not yet implemented";
// }

// void Building::notifyNoWater(string& utility) {
// 	// TODO - implement Building::notifyNoWater
// 	throw "Not yet implemented";
// }

// void Building::notifyWasteRemove(string& utility) {
// 	// TODO - implement Building::notifyWasteRemove
// 	throw "Not yet implemented";
// }

// void Building::notifySewageRemove(string& utility) {
// 	// TODO - implement Building::notifySewageRemove
// 	throw "Not yet implemented";
// }

// Building::Building(CityMediator* mediator, string type) {
// 	// TODO - implement Building::Building
// 	throw "Not yet implemented";
// }

// string Building::getType() {
// 	// TODO - implement Building::getType
// 	throw "Not yet implemented";
// }

// void Building::construct() {
// 	// TODO - implement Building::construct
// 	throw "Not yet implemented";
// }

// void Building::abstract_notifyChange() {
// 	// TODO - implement Building::abstract notifyChange
// 	throw "Not yet implemented";
// }

// void Building::accept(TaxAndBudgetVisitor* visitor) {
// 	// TODO - implement Building::accept
// 	throw "Not yet implemented";
// }
