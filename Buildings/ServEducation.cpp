#include "ServEducation.h"

/**
 * @class ServEducation
 * @brief Represents an educational service building.
 * 
 * This class provides methods to manage and display information about 
 * an education service, including its visitor capacity.
 */

/**
 * @brief Constructor for the ServEducation class.
 * 
 * Initializes a new instance of the ServEducation and outputs a creation message.
 */
ServEducation::ServEducation() {
    cout << BLACK << "\t-->Education service created" << RESET << endl;
}

/**
 * @brief Displays information about the education service.
 * 
 * This method outputs the number of visitors to the education service to the console.
 */
void ServEducation::displayBuildingInfo() {
    cout << "Education service with " << this->visitors << " visitors\n";
}

/**
 * @brief Gets the number of visitors for the education service.
 * 
 * @return The current number of visitors to the education service.
 */
int ServEducation::getVisitors() {
    return visitors;
}

/**
 * @brief Sets the number of visitors for the education service.
 * 
 * @param visitors The new number of visitors to set for the education service.
 */
void ServEducation::setVisitors(int visitors) {
    this->visitors = visitors;
}
