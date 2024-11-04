#ifndef INDFACTORY_H
#define INDFACTORY_H

#include "Industrial.h"

/**
 * @class IndFactory
 * @brief Represents an industrial factory building.
 *
 * The IndFactory class inherits from the Industrial class and implements the functionality
 * specific to an industrial factory, including production capacity, employee management,
 * and utility management.
 */
class IndFactory : public Industrial
{
public:
    IndFactory();
    ~IndFactory();

    /**
     * @brief Displays information about the industrial factory.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the production capacity of the industrial factory.
     * @return The production capacity.
     */
    int getProductionCapacity() override;

    /**
     * @brief Sets the production capacity of the industrial factory.
     * @param capacity The production capacity to set.
     */
    void setProductionCapacity(int capacity) override;

    // Observer pattern methods

    /**
     * @brief Calls the utility managers associated with this industrial factory.
     */
    void callUtilities();

    /**
     * @brief Gets the operational state of the industrial factory.
     * @return True if the factory is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the industrial factory.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of industrial building.
     * @return A string representing the building type.
     */
    string getBuildingType() override;

    /**
     * @brief Adds an employee to the industrial factory.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was successfully added, false otherwise.
     */
    bool addEmployee(Citizen *employee);

    /**
     * @brief Removes an employee from the industrial factory.
     * @param employee Pointer to the Citizen to be removed as an employee.
     */
    void removeEmployee(Citizen *employee);

    /**
     * @brief Notifies the industrial factory that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen *employee);

    /**
     * @brief Checks if the industrial factory has job openings.
     * @return True if there are job openings, false otherwise.
     */
    bool hasJob();

private:
    vector<Citizen *> employees; ///< List of employees in the industrial factory

    // Resources
    int cost = 1500; ///< Construction cost of the factory
    int jobCapacity = 10; ///< Maximum number of jobs available

    int woodCost = 20; ///< Wood cost for construction
    int concreteCost = 10; ///< Concrete cost for construction
    int steelCost = 10; ///< Steel cost for construction

    int electricityUsage = 10; ///< Electricity usage of the factory
    int waterUsage = 5; ///< Water usage of the factory

    int woodProduction = 5; ///< Wood production capacity of the factory

    string type = "Industrial Factory"; ///< Type of the building
    bool operational; ///< Operational state of the factory
};

#endif // INDFACTORY_H
