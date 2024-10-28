#include "ServHospital.h"
#include <iostream>
ServHospital::ServHospital() {
    cout << BLACK << "\t-->Security service created" << RESET << endl;
}

void ServHospital::displayBuildingInfo() {
    cout << "Security service with " << this->visitors << " visitors\n";
}

int ServHospital::getVisitors() {
    return visitors;
}

void ServHospital::setVisitors(int visitors) {
    this->visitors = visitors;
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