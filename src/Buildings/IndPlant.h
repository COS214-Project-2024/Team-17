#ifndef INDPLANT_H
#define INDPLANT_H

#include "Industrial.h"

/**
 * @class IndPlant
 * @brief Represents an industrial plant building.
 *
 * The IndPlant class inherits from the Industrial class and implements the functionality
 * specific to an industrial plant, including production capacity, employee management,
 * and utility management.
 */
class IndPlant : public Industrial
{
public:
    IndPlant();
    ~IndPlant();

    /**
     * @brief Displays information about the industrial plant.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the production capacity of the industrial plant.
     * @return The production capacity.
     */
    int getProductionCapacity() override;

    /**
     * @brief Sets the production capacity of the industrial plant.
     * @param capacity The production capacity to set.
     */
    void setProductionCapacity(int capacity) override;

    // Observer pattern methods

    /**
     * @brief Calls the utility managers associated with this industrial plant.
     */
    void callUtilities(); // Call Utilities in Buildings

    /**
     * @brief Gets the operational state of the industrial plant.
     * @return True if the plant is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the industrial plant.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of industrial building.
     * @return A string representing the building type.
     */
    string getBuildingType();

    /**
     * @brief Adds an employee to the industrial plant.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was successfully added, false otherwise.
     */
    bool addEmployee(Citizen *employee);

    /**
     * @brief Removes an employee from the industrial plant.
     * @param employee Pointer to the Citizen to be removed as an employee.
     */
    void removeEmployee(Citizen *employee);

    /**
     * @brief Notifies the industrial plant that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen *employee);

    /**
     * @brief Checks if the industrial plant has job openings.
     * @return True if there are job openings, false otherwise.
     */
    bool hasJob();

private:
    vector<Citizen *> employees; ///< List of employees in the industrial plant

    // Resources
    int cost = 1500; ///< Construction cost of the plant
    int jobCapacity = 10; ///< Maximum number of jobs available

    int woodCost = 10; ///< Wood cost for construction
    int concreteCost = 10; ///< Concrete cost for construction
    int steelCost = 20; ///< Steel cost for construction

    int electricityUsage = 10; ///< Electricity usage of the plant
    int waterUsage = 5; ///< Water usage of the plant

    int steelProduction = 5; ///< Steel production capacity of the plant

    string type = "Industrial Plant"; ///< Type of the building
    bool operational; ///< Operational state of the plant
};

#endif // INDPLANT_H
