#include "LandMonument.h"
// Error?
// LandMonument::LandMonument() {
//     cout << BLACK << "\t-->Monument created" << RESET << endl;
// }

void LandMonument::displayBuildingInfo() {
    cout << "Monument with " << this->visitors << " visitors\n";
}

int LandMonument::getVisitors() {
    return visitors;
}

void LandMonument::setVisitors(int visitors) {
    this->visitors = visitors;
}

	void LandMonument::callUtilities(){
        notifyUtilities();
    }

	bool LandMonument::getState(){
        return operational;
    }

	void LandMonument::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string LandMonument::getBuildingType(){
        return type;
    }