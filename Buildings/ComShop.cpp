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