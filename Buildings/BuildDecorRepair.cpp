#include "BuildDecorRepair.h"

/**
 * @class BuildDecorRepair
 * @brief Decorator class that adds repair functionality to a building.
 * 
 * This class extends BuildingDecorator to add additional behavior, specifically 
 * marking a building as "repaired" when displaying its information.
 */

/**
 * @brief Constructor for the BuildDecorRepair decorator.
 * 
 * @param b Pointer to a Building object to be decorated with repair functionality.
 */
BuildDecorRepair::BuildDecorRepair(Building* b) : BuildingDecorator(b) {}

/**
 * @brief Displays information about the building, indicating that it has been repaired.
 * 
 * If the wrapped building exists, it first calls the base building's 
 * display method, then adds information about the repair.
 */
void BuildDecorRepair::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    cout << "This building has been repaired." << endl;
}
