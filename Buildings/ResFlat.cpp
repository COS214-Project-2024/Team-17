#include "ResFlat.h"

/**
 * @class ResFlat
 * @brief Represents a residential flat building.
 * 
 * This class provides methods to manage and display information about 
 * a residential flat, including its capacity for people.
 */

/**
 * @brief Constructor for the ResFlat class.
 * 
 * Initializes a new instance of the ResFlat and outputs a creation message.
 */
ResFlat::ResFlat() {
    cout << BLACK << "\t-->Flat created" << RESET << endl;
}

/**
 * @brief Displays information about the flat.
 * 
 * This method outputs the capacity of the flat for accommodating people to the console.
 */
void ResFlat::displayBuildingInfo() {
    cout << "Flat for " << this->capacity << " people\n";
}

/**
 * @brief Gets the capacity of the flat.
 * 
 * @return The current capacity of the flat for people.
 */
int ResFlat::getCapacity() const {
    return capacity;
}

/**
 * @brief Sets the capacity of the flat.
 * 
 * @param capacity The new capacity to set for the flat.
 */
void ResFlat::setCapacity(int capacity) {
    this->capacity = capacity;
}
