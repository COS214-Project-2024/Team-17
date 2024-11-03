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