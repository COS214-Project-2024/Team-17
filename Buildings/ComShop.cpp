#include "ComShop.h"

/**
 * @class ComShop
 * @brief Represents a commercial shop building.
 * 
 * This class defines a shop with a specific job capacity and methods to 
 * display information about the shop and manage its job capacity.
 */

/**
 * @brief Constructor for the ComShop class.
 * 
 * Initializes a new instance of the ComShop and outputs a creation message.
 */
ComShop::ComShop() {
    cout << BLACK << "\t-->Shop created" << RESET << endl;
}

/**
 * @brief Displays information about the shop.
 * 
 * Outputs the job capacity of the shop.
 */
void ComShop::displayBuildingInfo() {
    cout << "Shop with " << this->jobCapacity << " jobs\n";
}

/**
 * @brief Gets the job capacity of the shop.
 * 
 * @return The current job capacity of the shop.
 */
int ComShop::getJobCapacity() {
    return jobCapacity;
}

/**
 * @brief Sets the job capacity of the shop.
 * 
 * @param capacity The new job capacity to be set for the shop.
 */
void ComShop::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}
