#include "IndPlant.h"

/**
 * @class IndPlant
 * @brief Represents an industrial plant building.
 * 
 * This class provides methods to manage and display information about 
 * an industrial plant, including its production capacity.
 */

/**
 * @brief Constructor for the IndPlant class.
 * 
 * Initializes a new instance of the IndPlant and outputs a creation message.
 */
IndPlant::IndPlant() {
    cout << BLACK << "\t-->Plant created" << RESET << endl;
}

/**
 * @brief Displays information about the plant.
 * 
 * This method outputs the production capacity of the plant to the console.
 */
void IndPlant::displayBuildingInfo() {
    cout << "Plant with production capacity of " << this->productionCapacity << " units\n";
}

/**
 * @brief Gets the production capacity of the plant.
 * 
 * @return The current production capacity of the plant.
 */
int IndPlant::getProductionCapacity() {
    return productionCapacity;
}

/**
 * @brief Sets the production capacity of the plant.
 * 
 * @param capacity The new production capacity to set for the plant.
 */
void IndPlant::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}
