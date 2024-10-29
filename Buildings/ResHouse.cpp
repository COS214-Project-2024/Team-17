#include "ResHouse.h"
// Error?
// ResHouse::ResHouse() {
//     cout << BLACK << "\t-->House created" << RESET << endl;
// }

void ResHouse::displayBuildingInfo() {
    cout << "House for " << this->capacity << " people\n";
}

int ResHouse::getCapacity() const {
    return capacity;
}

void ResHouse::setCapacity(int capacity) {
    this->capacity = capacity;
}

	void ResHouse::callUtilities(){
        notifyUtilities();
    }

	bool ResHouse::getState(){
        return operational;
    }

	void ResHouse::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ResHouse::getBuildingType(){
        return type;
    }