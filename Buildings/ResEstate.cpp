#include "ResEstate.h"

/**
 * @class ResEstate
 * @brief Represents a residential estate building.
 * 
 * This class provides methods to manage and display information about 
 * a residential estate, including its capacity for people.
 */

/**
 * @brief Constructor for the ResEstate class.
 * 
 * Initializes a new instance of the ResEstate and outputs a creation message.
 */
ResEstate::ResEstate() {
    cout << BLACK << "\t-->Estate created" << RESET << endl;
}

/**
 * @brief Displays information about the estate.
 * 
 * This method outputs the capacity of the estate for accommodating people to the console.
 */
void ResEstate::displayBuildingInfo() {
    cout << "Estate for " << this->capacity << " people\n";
}

/**
 * @brief Gets the capacity of the estate.
 * 
 * @return The current capacity of the estate for people.
 */
int ResEstate::getCapacity() const {
    return capacity;
}

/**
 * @brief Sets the capacity of the estate.
 * 
 * @param capacity The new capacity to set for the estate.
 */
void ResEstate::setCapacity(int capacity) {
    this->capacity = capacity;
}
