#include "ComMall.h"

/**
 * @class ComMall
 * @brief Represents a commercial mall building.
 * 
 * This class defines a mall with a specific job capacity and methods to 
 * display information about the mall and manage its job capacity.
 */

/**
 * @brief Constructor for the ComMall class.
 * 
 * Initializes a new instance of the ComMall and outputs a creation message.
 */
ComMall::ComMall() {
    cout << BLACK << "\t-->Mall created" << RESET << endl;
}

/**
 * @brief Displays information about the mall.
 * 
 * Outputs the job capacity of the mall.
 */
void ComMall::displayBuildingInfo() {
    cout << "Mall with " << this->jobCapacity << " jobs\n";
}

/**
 * @brief Gets the job capacity of the mall.
 * 
 * @return The current job capacity of the mall.
 */
int ComMall::getJobCapacity() {
    return jobCapacity;
}

/**
 * @brief Sets the job capacity of the mall.
 * 
 * @param capacity The new job capacity to be set for the mall.
 */
void ComMall::setJobCapacity(int capacity) {
    this->jobCapacity = capacity;
}
