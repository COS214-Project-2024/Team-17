#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"

// Forward declaration
class UtilityManager;

/**
 * @class Industrial
 * @brief Abstract base class for industrial buildings.
 *
 * The Industrial class inherits from the Building class and defines an interface
 * for industrial buildings, including methods for production capacity, employee management,
 * and utility management.
 */
class Industrial : public Building
{
public:
    /**
     * @brief Gets the production capacity of the industrial building.
     * @return The production capacity.
     */
    virtual int getProductionCapacity() = 0;

    /**
     * @brief Sets the production capacity of the industrial building.
     * @param capacity The production capacity to set.
     */
    virtual void setProductionCapacity(int capacity) = 0;

    /**
     * @brief Checks if the building meets the requirements for construction.
     * @return True if requirements are met, false otherwise.
     */
    bool checkBuildRequirements() override;

    // Observer pattern methods

    /**
     * @brief Gets the operational state of the industrial building.
     * @return True if the building is operational, false otherwise.
     */
    virtual bool getState();

    /**
     * @brief Gets the type of industrial building.
     * @return A string representing the building type.
     */
    virtual std::string getBuildingType();

    /**
     * @brief Attaches a utility manager to the building.
     * @param utility Pointer to the UtilityManager to attach.
     */
    void addUtility(UtilityManager *utility); // Attach

    /**
     * @brief Detaches a utility manager from the building.
     * @param utility Pointer to the UtilityManager to detach.
     */
    void removeUtility(UtilityManager *utility); // Detach

    /**
     * @brief Notifies attached utilities of changes in the building state.
     */
    void notifyUtilities(); // Notify

    /**
     * @brief Adds an employee to the industrial building.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was successfully added, false otherwise.
     */
    virtual bool addEmployee(Citizen *employee) = 0;

    /**
     * @brief Removes an employee from the industrial building.
     * @param employee Pointer to the Citizen to be removed as an employee.
     */
    virtual void removeEmployee(Citizen *employee) = 0;

    /**
     * @brief Notifies the industrial building that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    virtual void notifyEmployeeLeft(Citizen *employee) = 0;

    /**
     * @brief Moves in a resident to the industrial building.
     * @param resident Pointer to the Citizen who is moving in.
     * @return True if the move was successful, false otherwise.
     */
    virtual bool moveIn(Citizen *resident);

    /**
     * @brief Moves out a resident from the industrial building.
     * @param resident Pointer to the Citizen who is moving out.
     */
    virtual void moveOut(Citizen *resident);

    virtual int getElectricityUsage() = 0;
    virtual int getWaterUsage() = 0;
    virtual int getCurCitizenCount() = 0;


    // virtual bool checkBuildRequirements() = 0;
    // virtual void increaseJobs() = 0;
    // virtual void affectEmotionalState() = 0;
    // Additional methods can be added here

private:
    bool operational; ///< Operational state of the building
    vector<UtilityManager *> Utilities; ///< List of attached utility managers
};

#endif // INDUSTRIAL_H
