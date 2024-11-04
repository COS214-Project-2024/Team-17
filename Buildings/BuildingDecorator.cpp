#include "BuildingDecorator.h"

/**
 * @class BuildingDecorator
 * @brief Abstract base class for decorating buildings with additional features.
 * 
 * This class serves as a decorator for Building objects, allowing for 
 * the extension of building functionality by adding features dynamically.
 */

/**
 * @brief Constructor for the BuildingDecorator class.
 * 
 * @param b Pointer to a Building object that this decorator will enhance.
 */
BuildingDecorator::BuildingDecorator(Building* b) : building(b) {}

/**
 * @brief Displays information about the decorated building.
 * 
 * This method delegates the display call to the underlying Building object 
 * if it exists.
 */
void BuildingDecorator::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
}

/**
 * @brief Destructor for the BuildingDecorator class.
 * 
 * This destructor deletes the underlying Building object to prevent memory leaks.
 */
BuildingDecorator::~BuildingDecorator() {
    delete building;
}
