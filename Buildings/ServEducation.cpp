#include "ServEducation.h"

ServEducation::ServEducation() {
    cout << BLACK << "\t-->Education service created" << RESET << endl;
}

void ServEducation::displayBuildingInfo() {
    cout << "Education service with " << this->visitors << " visitors\n";
}

int ServEducation::getVisitors() {
    return visitors;
}

void ServEducation::setVisitors(int visitors) {
    this->visitors = visitors;
}