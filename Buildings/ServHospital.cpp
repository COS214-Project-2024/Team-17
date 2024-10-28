#include "ServHospital.h"
#include <iostream>
ServHospital::ServHospital() {
    std::cout << "Hospital Service Being Built!" << std::endl;
    operational = false; // constructing
}

	void ServHospital::callUtilities(){
        notifyUtilities();
    }

	bool ServHospital::getState(){
        return operational;
    }

	void ServHospital::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ServHospital::getBuildingType(){
        return type;
    }