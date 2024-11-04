#ifndef RESHOUSE_H
#define RESHOUSE_H

#include "../../colours.h" // Testing colours and other includes
#include "Residential.h"

/**
 * @class ResHouse
 * @brief Class representing a residential house.
 *
 * The ResHouse class inherits from the Residential class and provides
 * implementations for managing a residential house's capacity, state,
 * utilities, and residents.
 */
class ResHouse : public Residential
{
public:
    /**
     * @brief Constructor for ResHouse.
     */
    ResHouse();

    /**
     * @brief Destructor for ResHouse.
     */
    ~ResHouse();

    /**
     * @brief Displays information about the residential house.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the capacity of the residential house.
     * @return The maximum number of residents that can occupy the house.
     */
    int getCapacity() const override;

    /**
     * @brief Sets the capacity of the residential house.
     * @param capacity The maximum number of residents to set.
     */
    void setCapacity(int capacity) override;

    // Observer methods

    /**
     * @brief Calls utilities related to the residential house.
     */
    void callUtilities(); ///< Call Utilities in Buildings

    /**
     * @brief Gets the operational state of the residential house.
     * @return True if the house is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the residential house.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of residential building.
     * @return A string representing the type of building.
     */
    std::string getBuildingType();

    /**
     * @brief Notifies the residential house that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen *employee);

    /**
     * @brief Moves a resident into the residential house.
     * @param resident Pointer to the Citizen to be moved in.
     * @return True if the resident was successfully moved in, false otherwise.
     */
    bool moveIn(Citizen *resident);

    /**
     * @brief Moves a resident out of the residential house.
     * @param resident Pointer to the Citizen to be moved out.
     */
    void moveOut(Citizen *resident);

    int getElectricityUsage();
    int getWaterUsage();
    int getCurCitizenCount();

private:
    int capacity; ///< Maximum number of residents in the house
    string type = "Residential House"; ///< Type of the building
    bool operational; ///< Operational state of the residential house

    vector<Citizen *> residents; ///< List of residents in the house

    // Resource costs
    int cost = 2500; ///< Construction cost of the house
    int woodCost = 15; ///< Wood cost for construction
    int steelCost = 10; ///< Steel cost for construction
    int concreteCost = 20; ///< Concrete cost for construction

    int electricityUsage = 15; ///< Electricity usage of the house
    int waterUsage = 15; ///< Water usage of the house

    int popIncrease = 20; ///< Population increase from the house
};

#endif // RESHOUSE_H
