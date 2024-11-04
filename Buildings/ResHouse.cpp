#include "ResHouse.h"

/**
 * @class ResHouse
 * @brief Represents a residential house building.
 * 
 * This class provides methods to manage and display information about 
 * a residential house, including its capacity for people.
 */

/**
 * @brief Constructor for the ResHouse class.
 * 
 * Initializes a new instance of the ResHouse and outputs a creation message.
 */
ResHouse::ResHouse() {
    cout << BLACK << "\t-->House created" << RESET << endl;
}

/**
 * @brief Displays information about the house.
 * 
 * This method outputs the capacity of the house for accommodating people to the console.
 */
void ResHouse::displayBuildingInfo() {
    cout << "House for " << this->capacity << " people\n";
}

/**
 * @brief Gets the capacity of the house.
 * 
 * @return The current capacity of the house for people.
 */
int ResHouse::getCapacity() const {
    return capacity;
}

/**
 * @brief Sets the capacity of the house.
 * 
 * @param capacity The new capacity to set for the house.
 */
void ResHouse::setCapacity(int capacity) {
    this->capacity = capacity;
}
