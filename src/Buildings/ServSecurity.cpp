#include "ServSecurity.h"

ServSecurity::ServSecurity() {
    cout << BLACK << "\t-->Security service created" << RESET << endl;
}

void ServSecurity::displayBuildingInfo() {
    cout << "Security service with " << this->visitors << " visitors\n";
}

int ServSecurity::getVisitors() {
    return visitors;
}

void ServSecurity::setVisitors(int visitors) {
    this->visitors = visitors;
}

void ServSecurity::callUtilities(){
    notifyUtilities();
}

bool ServSecurity::getState(){
    return operational;
}

void ServSecurity::setState(bool state){
    if(operational!=state){
        operational = state;
        callUtilities();}
    else{
        cout<<"No change in state"<<endl;
    }
}

std::string ServSecurity::getBuildingType(){
    return type;
}