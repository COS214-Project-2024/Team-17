#include "Industrial.h"

// Observer Design Pattern
     void Industrial::addUtility(UtilityManager* utility) {
    	Utilities.push_back(utility);
		std::cout<<this->getBuildingType()<<" Has Utility Connection of type:"<<utility->getType()<<std::endl;
		
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