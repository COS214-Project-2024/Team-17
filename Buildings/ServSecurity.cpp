#include "ServSecurity.h"

/**
 * @class ServSecurity
 * @brief Represents a security service building.
 * 
 * This class provides methods to manage and display information about 
 * a security service, including its visitor capacity.
 */

/**
 * @brief Constructor for the ServSecurity class.
 * 
 * Initializes a new instance of the ServSecurity and outputs a creation message.
 */
ServSecurity::ServSecurity() {
    cout << BLACK << "\t-->Security service created" << RESET << endl;
}

/**
 * @brief Displays information about the security service.
 * 
 * This method outputs the number of visitors to the security service to the console.
 */
void ServSecurity::displayBuildingInfo() {
    cout << "Security service with " << this->visitors << " visitors\n";
}

/**
 * @brief Gets the number of visitors for the security service.
 * 
 * @return The current number of visitors to the security service.
 */
int ServSecurity::getVisitors() {
    return visitors;
}

/**
 * @brief Sets the number of visitors for the security service.
 * 
 * @param visitors The new number of visitors to set for the security service.
 */
void ServSecurity::setVisitors(int visitors) {
    this->visitors = visitors;
}
