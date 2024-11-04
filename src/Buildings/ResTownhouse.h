/**
 * @file ResTownhouse.h
 * @brief Declares the ResTownhouse class for residential townhouse buildings.
 */
#ifndef RESTOWNHOUSE_H
#define RESTOWNHOUSE_H

#include "Residential.h"
/**
 * @class ResTownhouse
 * @brief Represents a residential townhouse building.
 */
class ResTownhouse : public Residential
{
public:
    /**
     * @brief Constructs a ResTownhouse object.
     */
    ResTownhouse();
    /**
     * @brief Destroys the ResTownhouse object.
     */
    ~ResTownhouse();
    /**
     * @brief Displays information about the townhouse building.
     */
    void displayBuildingInfo() override;
    /**
     * @brief Gets the capacity of the townhouse.
     * @return The capacity as an integer.
     */
    int getCapacity() const override;
    /**
     * @brief Sets the capacity of the townhouse.
     * @param capacity The capacity to set.
     */
    void setCapacity(int capacity) override;

    // Observer
    /**
     * @brief Calls associated utility managers for the townhouse.
     */
    void callUtilities(); // call Utilities in Buildings
    /**
     * @brief Gets the operational state of the townhouse.
     * @return True if operational, false otherwise.
     */
    bool getState();
    /**
     * @brief Sets the operational state of the townhouse.
     * @param state The operational state to set.
     */
    void setState(bool state);
    /**
     * @brief Gets the building type as a string.
     * @return The building type.
     */
    std::string getBuildingType();
    /**
     * @brief Notifies when an employee has left.
     * @param employee Pointer to the employee who left.
     */
    void notifyEmployeeLeft(Citizen *employee);
    /**
     * @brief Moves in a resident to the townhouse.
     * @param resident Pointer to the resident to move in.
     * @return True if successful, false otherwise.
     */
    bool moveIn(Citizen *resident);
    /**
     * @brief Moves out a resident from the townhouse.
     * @param resident Pointer to the resident to move out.
     */
    void moveOut(Citizen *resident);

private:
    int capacity;
    string type = "Residential Townhouse";
    bool operational; // CS State

    vector<Citizen *> residents;
    // Resources
    int cost = 1500;

    int woodCost = 10;
    int steelCost = 10;
    int concreteCost = 15;

    int electricityUsage = 10;
    int waterUsage = 10;

    int popIncrease = 10;
};

#endif // RESTOWNHOUSE_H
