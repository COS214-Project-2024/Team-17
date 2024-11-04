#include "ComOffice.h"

/**
 * @class ComOffice
 * @brief Represents a commercial office building.
 * 
 * This class defines an office with a specific job capacity and methods to 
 * display information about the office and manage its job capacity.
 */

/**
 * @brief Constructor for the ComOffice class.
 * 
 * Initializes a new instance of the ComOffice and outputs a creation message.
 */
ComOffice::ComOffice() {
    cout << BLACK << "\t-->Office created" << RESET << endl;
}

/**
 * @brief Displays information about the office.
 * 
 * Outputs the job capacity of the office.
 */
void ComOffice::displayBuildingInfo() {
    cout << "Office with " << this->jobCapacity << " jobs\n";
}

/**
 * @brief Gets the job capacity of the office.
 * 
 * @return The current job capacity of the office.
 */
int ComOffice::getJobCapacity() {
    return jobCapacity;
}

/**
 * @brief Sets the job capacity of the office.
 * 
 * @param capacity The new job capacity to be set for the office.
 */
void ComOffice::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}
