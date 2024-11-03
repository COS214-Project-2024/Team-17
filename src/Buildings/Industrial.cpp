#include "Industrial.h"

bool Industrial::getState(){
    //  cout<<"commercial state"<<endl;
    return operational;
}

string Industrial::getBuildingType(){
    return "Industrial";
}

bool Industrial::checkBuildRequirements(){
    // add implementation
    return true;
}

// Observer Design Pattern
void Industrial::addUtility(UtilityManager* utility) {
    Utilities.push_back(utility);
    cout<<this->getBuildingType()<<" Has Utility Connection of type:"<<utility->getType()<<std::endl;
}
    
void Industrial::removeUtility(UtilityManager* utility) {
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

void Industrial::notifyUtilities(){
    for(UtilityManager* utility:Utilities){
        utility->update(this);
    }
}

bool Industrial::moveIn(Citizen* resident){
    return true;
}

void Industrial::moveOut(Citizen* resident){
}