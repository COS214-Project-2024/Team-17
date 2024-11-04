#include "ServEntertainment.h"

/**
 * @class ServEntertainment
 * @brief Represents an entertainment service building.
 * 
 * This class provides methods to manage and display information about 
 * an entertainment service, including its visitor capacity.
 */

/**
 * @brief Constructor for the ServEntertainment class.
 * 
 * Initializes a new instance of the ServEntertainment and outputs a creation message.
 */
ServEntertainment::ServEntertainment() {
    cout << BLACK << "\t-->Entertainment service created" << RESET << endl;
}

/**
 * @brief Displays information about the entertainment service.
 * 
 * This method outputs the number of visitors to the entertainment service to the console.
 */
void ServEntertainment::displayBuildingInfo() {
    cout << "Entertainment service with " << this->visitors << " visitors\n";
}

/**
 * @brief Gets the number of visitors for the entertainment service.
 * 
 * @return The current number of visitors to the entertainment service.
 */
int ServEntertainment::getVisitors() {
    return visitors;
}

/**
 * @brief Sets the number of visitors for the entertainment service.
 * 
 * @param visitors The new number of visitors to set for the entertainment service.
 */
void ServEntertainment::setVisitors(int visitors) {
    this->visitors = visitors;
}
