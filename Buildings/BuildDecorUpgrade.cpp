#include "BuildDecorUpgrade.h"

/**
 * @class BuildDecorUpgrade
 * @brief Decorator class that adds decorative upgrades to a building.
 * 
 * This class extends BuildingDecorator to add functionality indicating that 
 * a building has been upgraded with decorative elements.
 */

/**
 * @brief Constructor for the BuildDecorUpgrade decorator.
 * 
 * @param b Pointer to a Building object to be decorated with decorative elements.
 */
BuildDecorUpgrade::BuildDecorUpgrade(Building* b) : BuildingDecorator(b) {}

/**
 * @brief Displays information about the building, indicating decorative upgrades.
 * 
 * If the wrapped building exists, it first calls the base building's 
 * display method, then adds information about the decorative upgrade.
 */
void BuildDecorUpgrade::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    cout << "This building has been upgraded with decorative elements." << endl;
}
