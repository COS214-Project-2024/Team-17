#include "BuildingDecorator.h"

/**
 * @class BuildingDecorator
 * @brief Abstract decorator class for enhancing Building objects with additional functionality.
 *
 * BuildingDecorator implements the Decorator Design Pattern, allowing additional functionality
 * to be dynamically added to buildings without modifying the original Building class.
 */
BuildingDecorator::BuildingDecorator(Building *b) : Building()
{
    building = b;
}

/**
 * @brief Displays the information of the building, including any added decorations or enhancements.
 */
void BuildingDecorator::displayBuildingInfo()
{
    if (building)
    {
        building->displayBuildingInfo();
    }
}

/**
 * @brief Destructor for BuildingDecorator, ensuring proper cleanup of the decorated building.
 */
BuildingDecorator::~BuildingDecorator()
{
    delete building;
}

/**
 * @brief Checks if the building meets its build requirements.
 * 
 * @return True if the building meets all requirements, otherwise false.
 */
bool BuildingDecorator::checkBuildRequirements()
{
    return building->checkBuildRequirements();
}

/**
 * @brief Gets the current state of the building (e.g., active or inactive).
 * 
 * @return True if the building is active, otherwise false.
 */
bool BuildingDecorator::getState()
{
    return building->getState();
}

/**
 * @brief Adds an employee to the building.
 * 
 * @param employee A pointer to the Citizen object representing the employee.
 * @return True if the employee was added successfully, otherwise false.
 */
bool BuildingDecorator::addEmployee(Citizen *employee)
{
    return building->addEmployee(employee);
}

/**
 * @brief Removes an employee from the building.
 * 
 * @param employee A pointer to the Citizen object representing the employee to remove.
 */
void BuildingDecorator::removeEmployee(Citizen *employee)
{
    building->removeEmployee(employee);
}

/**
 * @brief Notifies the building that an employee has left.
 * 
 * @param employee A pointer to the Citizen object representing the employee who left.
 */
void BuildingDecorator::notifyEmployeeLeft(Citizen *employee)
{
    building->notifyEmployeeLeft(employee);
}

/**
 * @brief Checks if the building has job openings.
 * 
 * @return True if there are available jobs, otherwise false.
 */
bool BuildingDecorator::hasJob()
{
    return building->hasJob();
}

/**
 * @brief Moves a resident into the building.
 * 
 * @param resident A pointer to the Citizen object representing the resident moving in.
 * @return True if the resident was moved in successfully, otherwise false.
 */
bool BuildingDecorator::moveIn(Citizen *resident)
{
    return building->moveIn(resident);
}

/**
 * @brief Moves a resident out of the building.
 * 
 * @param resident A pointer to the Citizen object representing the resident moving out.
 */
void BuildingDecorator::moveOut(Citizen *resident)
{
    building->moveOut(resident);
}
