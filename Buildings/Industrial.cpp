#include "Industrial.h"

void Industrial::callUtilities(){
        notifyUtilities();
    }

	bool Industrial::getState(){
        //  cout<<"commercial state"<<endl;
        return operational;
    }

	void Industrial::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }
    	std::string Industrial::getBuildingType(){
        return "Industrial";
    }