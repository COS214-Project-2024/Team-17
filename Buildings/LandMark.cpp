#include "Landmark.h"

void Landmark::callUtilities(){
        notifyUtilities();
    }

	bool Landmark::getState(){
        //  cout<<"commercial state"<<endl;
        return operational;
    }

	void Landmark::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }
    	std::string Landmark::getBuildingType(){
        return "Landmark";
    }