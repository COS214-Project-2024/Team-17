#ifndef BUILDINGDECORATOR_H
#define BUILDINGDECORATOR_H

#include "Building.h"

/**
 * @class BuildingDecorator
 * @brief A base class for decorating buildings with additional functionality.
 *
 * This class acts as a decorator for the Building class, allowing 
 * additional features to be added to building objects dynamically.
 */
class BuildingDecorator : public Building
{
protected:
    Building *building; ///< Pointer to the building being decorated.

public:
    /**
     * @brief Constructs a BuildingDecorator with the specified building.
     * @param b Pointer to the Building object to be decorated.
     */
    BuildingDecorator(Building *b);

    /**
     * @brief Displays information about the building.
     *
     * Overrides the displayBuildingInfo method from the Building class.
     */
    virtual void displayBuildingInfo() override;

    /**
     * @brief Destructor for the BuildingDecorator.
     */
    virtual ~BuildingDecorator();

    /**
     * @brief Checks if building requirements are met.
     * @return True if requirements are met, otherwise false.
     */
    bool checkBuildRequirements() override;

    /**
     * @brief Gets the operational state of the building.
     * @return True if the building is operational, otherwise false.
     */
    bool getState() override;

    /**
     * @brief Adds an employee to the building.
     * @param employee Pointer to the Citizen object representing the employee.
     * @return True if the employee is added successfully, otherwise false.
     */
    virtual bool addEmployee(Citizen *employee);

    /**
     * @brief Removes an employee from the building.
     * @param employee Pointer to the Citizen object representing the employee.
     */
    virtual void removeEmployee(Citizen *employee);

    /**
     * @brief Notifies that an employee has left the building.
     * @param employee Pointer to the Citizen object representing the employee.
     */
    virtual void notifyEmployeeLeft(Citizen *employee);

    /**
     * @brief Checks if there are jobs available in the building.
     * @return True if jobs are available, otherwise false.
     */
    virtual bool hasJob();

    /**
     * @brief Moves a resident into the building.
     * @param resident Pointer to the Citizen object representing the resident.
     * @return True if the move is successful, otherwise false.
     */
    virtual bool moveIn(Citizen *resident);

    /**
     * @brief Moves a resident out of the building.
     * @param resident Pointer to the Citizen object representing the resident.
     */
    virtual void moveOut(Citizen *resident);
};

#endif // BUILDINGDECORATOR_H
