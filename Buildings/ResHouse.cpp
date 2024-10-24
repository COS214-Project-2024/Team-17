#include "ResHouse.h"

ResHouse::ResHouse() {
    cout << BLACK << "\t-->House created" << RESET << endl;
}

void ResHouse::displayBuildingInfo() {
    cout << "House for " << this->capacity << " people\n";
}

int ResHouse::getCapacity() const {
    return capacity;
}

void ResHouse::setCapacity(int capacity) {
    this->capacity = capacity;
}