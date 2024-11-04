#include "BuildDecorUpgrade.h"

/**
 * @class BuildDecorUpgrade
 * @brief A concrete decorator that adds decorative upgrades to a building.
 *
 * This class extends the functionality of a building by adding decorative elements, 
 * utilizing the Decorator Design Pattern to enhance building display information.
 */
BuildDecorUpgrade::BuildDecorUpgrade(Building* b) : BuildingDecorator(b) {}

/**
 * @brief Displays information about the building, including any decorative upgrades.
 *
 * This method first calls the base building's `displayBuildingInfo()` to show its 
 * existing information, then appends additional details about the decorative upgrade.
 */
void BuildDecorUpgrade::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    std::cout << "This building has been upgraded with decorative elements." << std::endl;
}
