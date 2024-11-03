#include "ComOffice.h"

ComOffice::ComOffice() {
    cout << BLACK << "\t-->Office created" << RESET << endl;
}

void ComOffice::displayBuildingInfo() {
    cout << "Office with " << this->jobCapacity << " jobs\n";
}

int ComOffice::getJobCapacity() {
    return jobCapacity;
}

void ComOffice::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}