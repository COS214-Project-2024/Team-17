#include "LandMonument.h"

/**
 * @class LandMonument
 * @brief Represents a monument landmark.
 * 
 * This class provides methods to manage and display information about 
 * a monument, including the number of visitors it can accommodate.
 */

/**
 * @brief Constructor for the LandMonument class.
 * 
 * Initializes a new instance of the LandMonument and outputs a creation message.
 */
LandMonument::LandMonument() {
    cout << BLACK << "\t-->Monument created" << RESET << endl;
}

/**
 * @brief Displays information about the monument.
 * 
 * This method outputs the number of visitors the monument can accommodate to the console.
 */
void LandMonument::displayBuildingInfo() {
    cout << "Monument with " << this->visitors << " visitors\n";
}

/**
 * @brief Gets the number of visitors that can be accommodated by the monument.
 * 
 * @return The current number of visitors the monument can accommodate.
 */
int LandMonument::getVisitors() {
    return visitors;
}

/**
 * @brief Sets the number of visitors that can be accommodated by the monument.
 * 
 * @param visitors The new number of visitors to set for the monument.
 */
void LandMonument::setVisitors(int visitors) {
    this->visitors = visitors;
}
