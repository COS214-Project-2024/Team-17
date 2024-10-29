#include "Commercial.h"

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
