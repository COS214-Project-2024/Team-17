#include "BuildDecorEconomic.h"

/**
 * @class BuildDecorEconomic
 * @brief Decorator class that adds economic upgrades to a building.
 * 
 * This class extends BuildingDecorator to add functionality indicating that 
 * a building has been upgraded with economic elements.
 */

/**
 * @brief Constructor for the BuildDecorEconomic decorator.
 * 
 * @param b Pointer to a Building object to be decorated with economic elements.
 */
BuildDecorEconomic::BuildDecorEconomic(Building* b) : BuildingDecorator(b) {}

/**
 * @brief Displays information about the building, indicating economic upgrades.
 * 
 * If the wrapped building exists, it first calls the base building's 
 * display method, then adds information about the economic upgrade.
 */
void BuildDecorEconomic::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    cout << "This building has been upgraded with economic elements." << endl;
}
