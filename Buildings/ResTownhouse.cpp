#include "ResTownhouse.h"

ResTownhouse::ResTownhouse() {
    cout << BLACK << "\t-->Townhouse created" << RESET << endl;
}

void ResTownhouse::displayBuildingInfo() {
    cout << "Townhouse for " << this->capacity << " people\n";
}

int ResTownhouse::getCapacity() const {
    return capacity;
}

void ResTownhouse::setCapacity(int capacity) {
    this->capacity = capacity;
}