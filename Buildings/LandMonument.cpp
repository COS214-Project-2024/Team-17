#include "LandMonument.h"

LandMonument::LandMonument() {
    cout << BLACK << "\t-->Monument created" << RESET << endl;
}

void LandMonument::displayBuildingInfo() {
    cout << "Monument with " << this->visitors << " visitors\n";
}

int LandMonument::getVisitors() {
    return visitors;
}

void LandMonument::setVisitors(int visitors) {
    this->visitors = visitors;
}