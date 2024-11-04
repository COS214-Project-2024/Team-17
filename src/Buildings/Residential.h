#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"

/**
 * @class Residential
 * @brief Abstract class representing a residential building in the city.
 *
 * The Residential class defines the interface for residential buildings,
 * including methods for managing capacity, residents, utilities, and
 * operational state.
 */
class Residential : public Building
{
public:
    /**
     * @brief Gets the capacity of the residential building.
     * @return The maximum number of residents that can occupy the building.
     */
    virtual int getCapacity() const = 0;

    /**
     * @brief Sets the capacity of the residential building.
     * @param capacity The maximum number of residents to set.
     */
    virtual void setCapacity(int capacity) = 0;

    /**
     * @brief Checks if the building meets construction requirements.
     * @return True if requirements are met, false otherwise.
     */
    bool checkBuildRequirements() override;

    // Observer methods

    /**
     * @brief Gets the operational state of the residential building.
     * @return True if the building is operational, false otherwise.
     */
    virtual bool getState() = 0;

    /**
     * @brief Gets the type of residential building.
     * @return A string representing the type of building.
     */
    virtual std::string getBuildingType() = 0;

    /**
     * @brief Attaches a utility manager to the building.
     * @param utility Pointer to the UtilityManager to attach.
     */
    void addUtility(UtilityManager *utility); ///< Attach a utility manager.

    /**
     * @brief Detaches a utility manager from the building.
     * @param utility Pointer to the UtilityManager to detach.
     */
    void removeUtility(UtilityManager *utility); ///< Detach a utility manager.

    /**
     * @brief Notifies all attached utilities of a change in the residential building.
     */
    void notifyUtilities(); ///< Notify attached utilities.

    /**
     * @brief Adds an employee to the residential building.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was added successfully, false otherwise.
     */
    virtual bool addEmployee(Citizen *employee);

    /**
     * @brief Removes an employee from the residential building.
     * @param employee Pointer to the Citizen to be removed.
     */
    virtual void removeEmployee(Citizen *employee);

    /**
     * @brief Notifies the residential building that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    virtual void notifyEmployeeLeft(Citizen *employee) = 0;

    /**
     * @brief Checks if there are job openings in the residential building.
     * @return True if there are job openings, false otherwise.
     */
    virtual bool hasJob();

    /**
     * @brief Moves a resident into the building.
     * @param resident Pointer to the Citizen to be moved in.
     * @return True if the resident was successfully moved in, false otherwise.
     */
    virtual bool moveIn(Citizen *resident) = 0;

    /**
     * @brief Moves a resident out of the building.
     * @param resident Pointer to the Citizen to be moved out.
     */
    virtual void moveOut(Citizen *resident) = 0;

private:
    bool operational; ///< Operational state of the residential building
    vector<UtilityManager *> Utilities; ///< List of attached utility managers
};

#endif // RESIDENTIAL_H
