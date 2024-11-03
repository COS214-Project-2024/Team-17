#include "IndFactory.h"

IndFactory::IndFactory() {
    cout << BLACK << "\t-->Factory created" << RESET << endl;
}

void IndFactory::displayBuildingInfo() {
    cout << "Factory with production capacity of " << this->productionCapacity << " units\n";
}

int IndFactory::getProductionCapacity() {
    return productionCapacity;
}

void IndFactory::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}