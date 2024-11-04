#include "Commercial.h"

/**
 * @class Commercial
 * @brief Represents a commercial building that utilizes various utilities and manages operational state.
 *
 * This class defines basic properties for a commercial building, including methods to check build requirements, 
 * manage utility connections, and notify utilities about changes in the building’s state.
 */

bool Commercial::getState(){
    //  cout<<"commercial state"<<endl;
    return operational;
}

string Commercial::getBuildingType(){
    return "Commercial";
}

bool Commercial::checkBuildRequirements(){
    // add implementation
    return true;
}

// Observer Design Pattern
     void Commercial::addUtility(UtilityManager* utility) {
    	Utilities.push_back(utility);
		std::cout<<this->getBuildingType()<<" Has Utility Connection of type:"<<utility->getType()<<std::endl;
		
    }
    
    void Commercial::removeUtility(UtilityManager* utility) {
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

void Commercial::notifyUtilities(){
    for(UtilityManager* utility:Utilities){
        utility->update(this);
    }
}

bool Commercial::moveIn(Citizen* resident){
    return true;
}

void Commercial::moveOut(Citizen* resident){
}
