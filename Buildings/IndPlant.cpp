#include "IndPlant.h"

IndPlant::IndPlant() {
    cout << BLACK << "\t-->Plant created" << RESET << endl;
}

void IndPlant::displayBuildingInfo() {
    cout << "Plant with production capacity of " << this->productionCapacity << " units\n";
}

int IndPlant::getProductionCapacity() {
    return productionCapacity;
}

void IndPlant::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}