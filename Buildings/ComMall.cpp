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

// Observer
void ComMall::callUtilities() {
    notifyUtilities();
}

bool ComMall::getState() {
    return operational;
}

void ComMall::setState(bool state) {
    if (operational != state) {
        operational = state;
        callUtilities();
    } else {
        cout << "No change in state" << endl;
    }
}

string ComMall::getBuildingType() {
    return type;
}