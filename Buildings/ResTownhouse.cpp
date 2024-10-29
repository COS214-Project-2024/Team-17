#include "ResTownhouse.h"
// Error?
// ResTownhouse::ResTownhouse() {
//     cout << BLACK << "\t-->Townhouse created" << RESET << endl;
// }

void ResTownhouse::displayBuildingInfo() {
    cout << "Townhouse for " << this->capacity << " people\n";
}

int ResTownhouse::getCapacity() const {
    return capacity;
}

void ResTownhouse::setCapacity(int capacity) {
    this->capacity = capacity;
}

	void ResTownhouse::callUtilities(){
        notifyUtilities();
    }

	bool ResTownhouse::getState(){
        return operational;
    }

	void ResTownhouse::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ResTownhouse::getBuildingType(){
        return type;
    }