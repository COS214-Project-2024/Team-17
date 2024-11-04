#include "IndWarehouse.h"

/**
 * @class IndWarehouse
 * @brief Represents an industrial warehouse building.
 * 
 * This class provides methods to manage and display information about 
 * an industrial warehouse, including its production capacity.
 */

/**
 * @brief Constructor for the IndWarehouse class.
 * 
 * Initializes a new instance of the IndWarehouse and outputs a creation message.
 */
IndWarehouse::IndWarehouse() {
    cout << BLACK << "\t-->Warehouse created" << RESET << endl;
}

/**
 * @brief Displays information about the warehouse.
 * 
 * This method outputs the production capacity of the warehouse to the console.
 */
void IndWarehouse::displayBuildingInfo() {
    cout << "Warehouse with production capacity of " << this->productionCapacity << " units\n";
}

/**
 * @brief Gets the production capacity of the warehouse.
 * 
 * @return The current production capacity of the warehouse.
 */
int IndWarehouse::getProductionCapacity() {
    return productionCapacity;
}

/**
 * @brief Sets the production capacity of the warehouse.
 * 
 * @param capacity The new production capacity to set for the warehouse.
 */
void IndWarehouse::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}
