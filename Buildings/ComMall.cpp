#include "ComMall.h"

ComMall::ComMall() {
    cout << BLACK << "\t-->Mall created" << RESET << endl;
}

void ComMall::displayBuildingInfo() {
    cout << "Mall with " << this->jobCapacity << " jobs\n";
}

int ComMall::getJobCapacity() {
    return jobCapacity;
}

void ComMall::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}