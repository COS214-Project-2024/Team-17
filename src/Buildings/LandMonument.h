#ifndef LANDMONUMENT_H
#define LANDMONUMENT_H

#include "Landmark.h"

/**
 * @class LandMonument
 * @brief Class representing a monument landmark.
 *
 * The LandMonument class inherits from the Landmark class and provides
 * implementations for managing monument-related operations, including visitor
 * management, utilities, and employee handling.
 */
class LandMonument : public Landmark
{
public:
    /**
     * @brief Constructor for LandMonument.
     */
    LandMonument();

    /**
     * @brief Destructor for LandMonument.
     */
    ~LandMonument();

    /**
     * @brief Displays information about the monument landmark.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the number of visitors currently in the monument.
     * @return The number of visitors.
     */
    int getVisitors() override;

    /**
     * @brief Sets the number of visitors in the monument.
     * @param visitors The number of visitors to set.
     */
    void setVisitors(int visitors) override;

    // Observer methods

    /**
     * @brief Calls utilities related to the monument landmark.
     */
    void callUtilities(); ///< Call Utilities in Buildings

    /**
     * @brief Gets the operational state of the monument.
     * @return True if the monument is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the monument.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of landmark.
     * @return A string representing the type of building.
     */
    string getBuildingType();

    /**
     * @brief Adds an employee to the monument.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was successfully added, false otherwise.
     */
    bool addEmployee(Citizen *employee);

    /**
     * @brief Removes an employee from the monument.
     * @param employee Pointer to the Citizen to be removed as an employee.
     */
    void removeEmployee(Citizen *employee);

    /**
     * @brief Notifies the monument that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen *employee);

    /**
     * @brief Checks if there are available jobs in the monument.
     * @return True if there are job openings, false otherwise.
     */
    bool hasJob();

private:
    vector<Citizen *> employees; ///< List of employees working in the monument

    // Resource costs
    int cost = 1500; ///< Construction cost of the monument
    int jobCapacity = 10; ///< Maximum number of employees in the monument

    int woodCost = 10; ///< Wood cost for construction
    int concreteCost = 20; ///< Concrete cost for construction
    int steelCost = 10; ///< Steel cost for construction

    int electricityUsage = 5; ///< Electricity usage of the monument
    int waterUsage = 10; ///< Water usage of the monument

    int happiness = 10; ///< Happiness increase provided by the monument

    int visitors; ///< Current number of visitors in the monument
    string type = "Landmark Monument"; ///< Type of the landmark
    bool operational; ///< Operational state of the monument
};

#endif // LANDMONUMENT_H
