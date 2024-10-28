#include "ComShop.h"

ComShop::ComShop() {
    cout << BLACK << "\t-->Shop created" << RESET << endl;
}

void ComShop::displayBuildingInfo() {
    cout << "Shop with " << this->jobCapacity << " jobs\n";
}

int ComShop::getJobCapacity() {
    return jobCapacity;
}

void ComShop::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}

	void ComShop::callUtilities(){
        notifyUtilities();
    }

	bool ComShop::getState(){
        return operational;
    }

	void ComShop::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ComShop::getBuildingType(){
        return type;
    }