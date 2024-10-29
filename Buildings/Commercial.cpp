#include "Commercial.h"

// void Commercial::operation() {
// 	// TODO - implement Commercial::operation
// 	throw "Not yet implemented";
// }
void Commercial::callUtilities(){
        notifyUtilities();
    }

	bool Commercial::getState(){
        //  cout<<"commercial state"<<endl;
        return operational;
    }

	void Commercial::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }
    	std::string Commercial::getBuildingType(){
        return "Commercial";
    }