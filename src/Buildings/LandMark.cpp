#include "Landmark.h"

bool Landmark::getState(){
    //  cout<<"commercial state"<<endl;
    return operational;
}

string Landmark::getBuildingType(){
    return "Landmark";
}

bool Landmark::checkBuildRequirements(){
    // add implementation
    return true;
}

// Observer Design Pattern
     void Landmark::addUtility(UtilityManager* utility) {
    	Utilities.push_back(utility);
		std::cout<<this->getBuildingType()<<" Has Utility Connection of type:"<<utility->getType()<<std::endl;
		
    }
    
    void Landmark::removeUtility(UtilityManager* utility) {
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

void Landmark::notifyUtilities(){
    for(UtilityManager* utility:Utilities){
        utility->update(this);
    }
}

bool Landmark::moveIn(Citizen* resident){
    return true;
}

void Landmark::moveOut(Citizen* resident){
}