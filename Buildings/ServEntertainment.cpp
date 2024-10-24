#include "ServEntertainment.h"

ServEntertainment::ServEntertainment() {
    cout << BLACK << "\t-->Entertainment service created" << RESET << endl;
}

void ServEntertainment::displayBuildingInfo() {
    cout << "Entertainment service with " << this->visitors << " visitors\n";
}

int ServEntertainment::getVisitors() {
    return visitors;
}

void ServEntertainment::setVisitors(int visitors) {
    this->visitors = visitors;
}