#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"

class UtilityManager;
/**
 * @class Commercial
 * @brief Abstract base class representing a commercial building.
 *
 * The Commercial class extends the Building class and provides
 * an interface for specific types of commercial buildings.
 */
class Commercial : public Building
{
public:
    /**
     * @brief Gets the job capacity of the commercial building.
     * @return The number of jobs the building can accommodate.
     */
    virtual int getJobCapacity() = 0;

    /**
     * @brief Sets the job capacity of the commercial building.
     * @param capacity The new job capacity to set.
     */
    virtual void setJobCapacity(int capacity) = 0;

    /**
     * @brief Gets the operational state of the commercial building.
     * @return True if the building is operational, false otherwise.
     */
    virtual bool getState();

    /**
     * @brief Gets the type of the building.
     * @return A string representing the building type.
     */
    virtual string getBuildingType();

    /**
     * @brief Checks if the building meets the requirements for construction.
     * @return True if the building meets the requirements, false otherwise.
     */
    bool checkBuildRequirements() override;

    // Observer pattern

    /**
     * @brief Attaches a utility manager to the commercial building.
     * @param utility A pointer to the UtilityManager to attach.
     */
    void addUtility(UtilityManager *utility); // attach

    /**
     * @brief Detaches a utility manager from the commercial building.
     * @param utility A pointer to the UtilityManager to detach.
     */
    void removeUtility(UtilityManager *utility); // detach

    /**
     * @brief Notifies all attached utility managers of a change.
     */
    void notifyUtilities(); // notify

    /**
     * @brief Adds an employee to the commercial building.
     * @param employee A pointer to the Citizen representing the employee.
     * @return True if the employee was added successfully, false otherwise.
     */
    virtual bool addEmployee(Citizen *employee) = 0;

    /**
     * @brief Removes an employee from the commercial building.
     * @param employee A pointer to the Citizen representing the employee.
     */
    virtual void removeEmployee(Citizen *employee) = 0;

    /**
     * @brief Notifies that an employee has left the commercial building.
     * @param employee A pointer to the Citizen representing the employee.
     */
    virtual void notifyEmployeeLeft(Citizen *employee) = 0;

    /**
     * @brief Moves a resident into the commercial building.
     * @param resident A pointer to the Citizen representing the resident.
     * @return True if the resident moved in successfully, false otherwise.
     */
    virtual bool moveIn(Citizen *resident);

    /**
     * @brief Moves a resident out of the commercial building.
     * @param resident A pointer to the Citizen representing the resident.
     */
    virtual void moveOut(Citizen *resident);

	virtual int getElectricityUsage() = 0;
    virtual int getWaterUsage() = 0;
    virtual int getCurCitizenCount() = 0;


private:
    bool operational; ///< Operational state of the building (part of Observer).
    vector<UtilityManager *> Utilities; ///< List of attached utility managers.
};

#endif // COMMERCIAL_H