#ifndef LANDPARK_H
#define LANDPARK_H

#include "Landmark.h"

/**
 * @class LandPark
 * @brief Class representing a park landmark.
 *
 * The LandPark class inherits from the Landmark class and provides
 * implementations for managing park-related operations, including visitor
 * management, utilities, and employee handling.
 */
class LandPark : public Landmark
{
public:
    /**
     * @brief Constructor for LandPark.
     */
    LandPark();

    /**
     * @brief Destructor for LandPark.
     */
    ~LandPark();

    /**
     * @brief Displays information about the park landmark.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the number of visitors currently in the park.
     * @return The number of visitors.
     */
    int getVisitors() override;

    /**
     * @brief Sets the number of visitors in the park.
     * @param visitors The number of visitors to set.
     */
    void setVisitors(int visitors) override;

    // Observer methods

    /**
     * @brief Calls utilities related to the park landmark.
     */
    void callUtilities(); ///< Call Utilities in Buildings

    /**
     * @brief Gets the operational state of the park.
     * @return True if the park is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the park.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of landmark.
     * @return A string representing the type of building.
     */
    std::string getBuildingType();

    /**
     * @brief Adds an employee to the park.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was successfully added, false otherwise.
     */
    bool addEmployee(Citizen *employee);

    /**
     * @brief Removes an employee from the park.
     * @param employee Pointer to the Citizen to be removed as an employee.
     */
    void removeEmployee(Citizen *employee);

    /**
     * @brief Notifies the park that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen *employee);

    /**
     * @brief Checks if there are available jobs in the park.
     * @return True if there are job openings, false otherwise.
     */
    bool hasJob();

private:
    vector<Citizen *> employees; ///< List of employees working in the park

    // Resource costs
    int cost = 1000; ///< Construction cost of the park
    int jobCapacity = 10; ///< Maximum number of employees in the park

    int woodCost = 25; ///< Wood cost for construction
    int concreteCost = 5; ///< Concrete cost for construction
    int steelCost = 10; ///< Steel cost for construction

    int electricityUsage = 5; ///< Electricity usage of the park
    int waterUsage = 10; ///< Water usage of the park

    int happiness = 5; ///< Happiness increase provided by the park

    int visitors; ///< Current number of visitors in the park
    string type = "Landmark Park"; ///< Type of the landmark
    bool operational; ///< Operational state of the park
};

#endif // LANDPARK_H
