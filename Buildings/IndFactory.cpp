#include "IndFactory.h"

/**
 * @class IndFactory
 * @brief Represents an industrial factory building.
 * 
 * This class provides methods to manage and display information about 
 * an industrial factory, including its production capacity.
 */

/**
 * @brief Constructor for the IndFactory class.
 * 
 * Initializes a new instance of the IndFactory and outputs a creation message.
 */
IndFactory::IndFactory() {
    cout << BLACK << "\t-->Factory created" << RESET << endl;
}

/**
 * @brief Displays information about the factory.
 * 
 * This method outputs the production capacity of the factory to the console.
 */
void IndFactory::displayBuildingInfo() {
    cout << "Factory with production capacity of " << this->productionCapacity << " units\n";
}

/**
 * @brief Gets the production capacity of the factory.
 * 
 * @return The current production capacity of the factory.
 */
int IndFactory::getProductionCapacity() {
    return productionCapacity;
}

/**
 * @brief Sets the production capacity of the factory.
 * 
 * @param capacity The new production capacity to set for the factory.
 */
void IndFactory::setProductionCapacity(int capacity) {
    this->productionCapacity = capacity;
}
