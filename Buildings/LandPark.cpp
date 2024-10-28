#include "LandPark.h"

LandPark::LandPark() {
    cout << BLACK << "\t-->Park created" << RESET << endl;
}

void LandPark::displayBuildingInfo() {
    cout << "Park with " << this->visitors << " visitors\n";
}

int LandPark::getVisitors() {
    return visitors;
}

void LandPark::setVisitors(int visitors) {
    this->visitors = visitors;
}

	void LandPark::callUtilities(){
        notifyUtilities();
    }

	bool LandPark::getState(){
        return operational;
    }

	void LandPark::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string LandPark::getBuildingType(){
        return type;
    }