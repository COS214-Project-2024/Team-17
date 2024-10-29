#include "ComOffice.h"
// Error?
// ComOffice::ComOffice() {
//     cout << BLACK << "\t-->Office created" << RESET << endl;
// }

void ComOffice::displayBuildingInfo() {
    cout << "Office with " << this->jobCapacity << " jobs\n";
}

int ComOffice::getJobCapacity() {
    return jobCapacity;
}

void ComOffice::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}

	void ComOffice::callUtilities(){
        notifyUtilities();
    }

	bool ComOffice::getState(){
        return operational;
    }

	void ComOffice::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ComOffice::getBuildingType(){
        return type;
    }