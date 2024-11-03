#include "ResEstate.h"

ResEstate::ResEstate() {
    cout << BLACK << "\t-->Estate created" << RESET << endl;
}

void ResEstate::displayBuildingInfo() {
    cout << "Estate for " << this->capacity << " people\n";
}

int ResEstate::getCapacity() const {
    return capacity;
}

void ResEstate::setCapacity(int capacity) {
    this->capacity = capacity;
}