#include "LandPark.h"

LandPark::LandPark() {
    cout << BLACK << "\t-->Park created" << RESET << endl;
}

void LandPark::displayBuildingInfo() {
    cout << "Park with " << this->visitors << " visitors\n";
}

int LandPark::getVisitors() {
    return visitors;
}

void LandPark::setVisitors(int visitors) {
    this->visitors = visitors;
}