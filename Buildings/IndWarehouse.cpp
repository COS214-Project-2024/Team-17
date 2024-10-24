#include "IndWarehouse.h"

IndWarehouse::IndWarehouse() {
    cout << BLACK << "\t-->Warehouse created" << RESET << endl;
}

void IndWarehouse::displayBuildingInfo() {
    cout << "Warehouse with production capacity of " << this->productionCapacity << " units\n";
}

int IndWarehouse::getProductionCapacity() {
    return productionCapacity;
}

void IndWarehouse::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}