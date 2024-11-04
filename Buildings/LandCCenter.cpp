#include "LandCCenter.h"

/**
 * @class LandCCenter
 * @brief Represents a community center landmark.
 * 
 * This class provides methods to manage and display information about 
 * a community center, including the number of visitors it can accommodate.
 */

/**
 * @brief Constructor for the LandCCenter class.
 * 
 * Initializes a new instance of the LandCCenter and outputs a creation message.
 */
LandCCenter::LandCCenter() {
    cout << BLACK << "\t-->Community center created" << RESET << endl;
}

/**
 * @brief Displays information about the community center.
 * 
 * This method outputs the number of visitors the community center can accommodate to the console.
 */
void LandCCenter::displayBuildingInfo() {
    cout << "Community center with " << this->visitors << " visitors\n";
}

/**
 * @brief Gets the number of visitors that can be accommodated by the community center.
 * 
 * @return The current number of visitors the community center can accommodate.
 */
int LandCCenter::getVisitors() {
    return visitors;
}

/**
 * @brief Sets the number of visitors that can be accommodated by the community center.
 * 
 * @param visitors The new number of visitors to set for the community center.
 */
void LandCCenter::setVisitors(int visitors) {
    this->visitors = visitors;
}
