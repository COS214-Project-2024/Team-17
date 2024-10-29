#include "ResFlat.h"
// Error?
// ResFlat::ResFlat() {
//     cout << BLACK << "\t-->Flat created" << RESET << endl;
// }

void ResFlat::displayBuildingInfo() {
    cout << "Flat for " << this->capacity << " people\n";
}

int ResFlat::getCapacity() const {
    return capacity;
}

void ResFlat::setCapacity(int capacity) {
    this->capacity = capacity;
}

	void ResFlat::callUtilities(){
        notifyUtilities();
    }

	bool ResFlat::getState(){
        return operational;
    }

	void ResFlat::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ResFlat::getBuildingType(){
        return type;
    }