#include "ResFlat.h"

ResFlat::ResFlat() {
    cout << BLACK << "\t-->Flat created" << RESET << endl;
}

void ResFlat::displayBuildingInfo() {
    cout << "Flat for " << this->capacity << " people\n";
}

int ResFlat::getCapacity() const {
    return capacity;
}

void ResFlat::setCapacity(int capacity) {
    this->capacity = capacity;
}