#include "LandPark.h"

/**
 * @class LandPark
 * @brief Represents a park landmark.
 * 
 * This class provides methods to manage and display information about 
 * a park, including the number of visitors it can accommodate.
 */

/**
 * @brief Constructor for the LandPark class.
 * 
 * Initializes a new instance of the LandPark and outputs a creation message.
 */
LandPark::LandPark() {
    cout << BLACK << "\t-->Park created" << RESET << endl;
}

/**
 * @brief Displays information about the park.
 * 
 * This method outputs the number of visitors the park can accommodate to the console.
 */
void LandPark::displayBuildingInfo() {
    cout << "Park with " << this->visitors << " visitors\n";
}

/**
 * @brief Gets the number of visitors that can be accommodated by the park.
 * 
 * @return The current number of visitors the park can accommodate.
 */
int LandPark::getVisitors() {
    return visitors;
}

/**
 * @brief Sets the number of visitors that can be accommodated by the park.
 * 
 * @param visitors The new number of visitors to set for the park.
 */
void LandPark::setVisitors(int visitors) {
    this->visitors = visitors;
}
