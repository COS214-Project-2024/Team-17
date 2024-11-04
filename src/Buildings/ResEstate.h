#ifndef RESESTATE_H
#define RESESTATE_H

#include "Residential.h"

/**
 * @class ResEstate
 * @brief Class representing a residential estate.
 *
 * The ResEstate class inherits from the Residential class and provides
 * implementations for managing a residential estate's capacity, state,
 * utilities, and residents.
 */
class ResEstate : public Residential
{
public:
    /**
     * @brief Constructor for ResEstate.
     */
    ResEstate();

    /**
     * @brief Destructor for ResEstate.
     */
    ~ResEstate();

    /**
     * @brief Displays information about the residential estate.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the capacity of the residential estate.
     * @return The maximum number of residents that can occupy the estate.
     */
    int getCapacity() const override;

    /**
     * @brief Sets the capacity of the residential estate.
     * @param capacity The maximum number of residents to set.
     */
    void setCapacity(int capacity) override;

    // Observer methods

    /**
     * @brief Calls utilities related to the residential estate.
     */
    void callUtilities(); ///< Call Utilities in Buildings

    /**
     * @brief Gets the operational state of the residential estate.
     * @return True if the estate is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the residential estate.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of residential building.
     * @return A string representing the type of building.
     */
    std::string getBuildingType();

    /**
     * @brief Notifies the residential estate that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen *employee) override;

    /**
     * @brief Moves a resident into the residential estate.
     * @param resident Pointer to the Citizen to be moved in.
     * @return True if the resident was successfully moved in, false otherwise.
     */
    bool moveIn(Citizen *resident);

    /**
     * @brief Moves a resident out of the residential estate.
     * @param resident Pointer to the Citizen to be moved out.
     */
    void moveOut(Citizen *resident);

private:
    int capacity; ///< Maximum number of residents in the estate
    string type = "Residential Estate"; ///< Type of the building
    bool operational; ///< Operational state of the residential estate

    vector<Citizen *> residents; ///< List of residents in the estate

    // Resource costs
    int cost = 4000; ///< Construction cost of the estate
    int woodCost = 20; ///< Wood cost for construction
    int steelCost = 20; ///< Steel cost for construction
    int concreteCost = 20; ///< Concrete cost for construction

    int electricityUsage = 20; ///< Electricity usage of the estate
    int waterUsage = 20; ///< Water usage of the estate

    int popIncrease = 50; ///< Population increase from the estate
};

#endif // RESESTATE_H
