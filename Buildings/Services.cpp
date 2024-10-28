#include "Services.h"

void Services::callUtilities(){
        notifyUtilities();
    }

	bool Services::getState(){
        //  cout<<"commercial state"<<endl;
        return operational;
    }

	void Services::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }
    	std::string Services::getBuildingType(){
        return "Residential";
    }