#include "LandCCenter.h"

LandCCenter::LandCCenter() {
    cout << BLACK << "\t-->Community center created" << RESET << endl;
}

void LandCCenter::displayBuildingInfo() {
    cout << "Community center with " << this->visitors << " visitors\n";
}

int LandCCenter::getVisitors() {
    return visitors;
}

void LandCCenter::setVisitors(int visitors) {
    this->visitors = visitors;
}