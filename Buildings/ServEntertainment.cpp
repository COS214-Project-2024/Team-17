#include "ServEntertainment.h"
// Error?
// ServEntertainment::ServEntertainment() {
//     cout << BLACK << "\t-->Entertainment service created" << RESET << endl;
// }

void ServEntertainment::displayBuildingInfo() {
    cout << "Entertainment service with " << this->visitors << " visitors\n";
}

int ServEntertainment::getVisitors() {
    return visitors;
}

void ServEntertainment::setVisitors(int visitors) {
    this->visitors = visitors;
}

	void ServEntertainment::callUtilities(){
        notifyUtilities();
    }

	bool ServEntertainment::getState(){
        return operational;
    }

	void ServEntertainment::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ServEntertainment::getBuildingType(){
        return type;
    }