#ifndef INDWAREHOUSE_H
#define INDWAREHOUSE_H

#include "Industrial.h"

/**
 * @class IndWarehouse
 * @brief Represents an industrial warehouse building.
 *
 * The IndWarehouse class inherits from the Industrial class and provides specific
 * implementations for managing production capacity, resources, and employee interactions
 * at a warehouse facility.
 */
class IndWarehouse : public Industrial {
public:
    /**
     * @brief Default constructor for IndWarehouse.
     */
    IndWarehouse();

    /**
     * @brief Destructor for IndWarehouse.
     */
    ~IndWarehouse();

    /**
     * @brief Displays information about the industrial warehouse building.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the production capacity of the warehouse.
     * @return The production capacity.
     */
    int getProductionCapacity() override;

    /**
     * @brief Sets the production capacity of the warehouse.
     * @param capacity The production capacity to set.
     */
    void setProductionCapacity(int capacity) override;

    // Observer methods

    /**
     * @brief Calls the utilities for the industrial warehouse.
     */
    void callUtilities(); // Call Utilities in Buildings

    /**
     * @brief Gets the operational state of the warehouse.
     * @return True if the warehouse is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the warehouse.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of building.
     * @return A string representing the building type.
     */
    std::string getBuildingType();

    /**
     * @brief Adds an employee to the industrial warehouse.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was successfully added, false otherwise.
     */
    bool addEmployee(Citizen* employee);

    /**
     * @brief Removes an employee from the industrial warehouse.
     * @param employee Pointer to the Citizen to be removed as an employee.
     */
    void removeEmployee(Citizen* employee);

    /**
     * @brief Notifies the industrial warehouse that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen* employee);

    /**
     * @brief Checks if there are available jobs in the industrial warehouse.
     * @return True if there are jobs available, false otherwise.
     */
    bool hasJob();

	int getElectricityUsage();
    int getWaterUsage();
    int getCurCitizenCount();

private:
    vector<Citizen*> employees; ///< List of employees at the warehouse

    // Resources
    int cost = 1500; ///< Cost to build the warehouse
    int jobCapacity = 10; ///< Maximum number of jobs available

    int woodCost = 10; ///< Wood cost for building
    int concreteCost = 20; ///< Concrete cost for building
    int steelCost = 10; ///< Steel cost for building

    int electricityUsage = 10; ///< Electricity usage of the warehouse
    int waterUsage = 5; ///< Water usage of the warehouse

    int concreteProduction = 5; ///< Concrete produced by the warehouse

    string type = "Industrial Warehouse"; ///< Type of building
    bool operational; ///< Operational state of the warehouse
};

#endif // INDWAREHOUSE_H
