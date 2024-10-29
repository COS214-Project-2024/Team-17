#include "ServEducation.h"
// Error?
// ServEducation::ServEducation() {
//     cout << BLACK << "\t-->Education service created" << RESET << endl;
// }

void ServEducation::displayBuildingInfo() {
    cout << "Education service with " << this->visitors << " visitors\n";
}

int ServEducation::getVisitors() {
    return visitors;
}

void ServEducation::setVisitors(int visitors) {
    this->visitors = visitors;
}

	void ServEducation::callUtilities(){
        notifyUtilities();
    }

	bool ServEducation::getState(){
        return operational;
    }

	void ServEducation::setState(bool state){
        if(operational!=state){
        operational = state;
        callUtilities();}
        else{
            cout<<"No change in state"<<endl;
        }
    }

	std::string ServEducation::getBuildingType(){
        return type;
    }