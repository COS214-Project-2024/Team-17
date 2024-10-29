#include "Residential.h"

void Residential::callUtilities(){
        notifyUtilities();
    }

	bool Residential::getState(){
        //  cout<<"commercial state"<<endl;
        return operational;
    }

	void Residential::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }
    	std::string Residential::getBuildingType(){
        return "Residential";
    }