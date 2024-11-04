#include "ResTownhouse.h"

/**
 * @class ResTownhouse
 * @brief Represents a residential townhouse building.
 * 
 * This class provides methods to manage and display information about 
 * a residential townhouse, including its capacity for people.
 */

/**
 * @brief Constructor for the ResTownhouse class.
 * 
 * Initializes a new instance of the ResTownhouse and outputs a creation message.
 */
ResTownhouse::ResTownhouse() {
    cout << BLACK << "\t-->Townhouse created" << RESET << endl;
}

/**
 * @brief Displays information about the townhouse.
 * 
 * This method outputs the capacity of the townhouse for accommodating people to the console.
 */
void ResTownhouse::displayBuildingInfo() {
    cout << "Townhouse for " << this->capacity << " people\n";
}

/**
 * @brief Gets the capacity of the townhouse.
 * 
 * @return The current capacity of the townhouse for people.
 */
int ResTownhouse::getCapacity() const {
    return capacity;
}

/**
 * @brief Sets the capacity of the townhouse.
 * 
 * @param capacity The new capacity to set for the townhouse.
 */
void ResTownhouse::setCapacity(int capacity) {
    this->capacity = capacity;
}
