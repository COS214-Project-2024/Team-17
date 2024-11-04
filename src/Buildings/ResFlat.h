#ifndef RESFLAT_H
#define RESFLAT_H

#include "Residential.h"

/**
 * @class ResFlat
 * @brief Class representing a residential flat.
 *
 * The ResFlat class inherits from the Residential class and provides
 * implementations for managing a residential flat's capacity, state,
 * utilities, and residents.
 */
class ResFlat : public Residential
{
public:
    /**
     * @brief Constructor for ResFlat.
     */
    ResFlat();

    /**
     * @brief Destructor for ResFlat.
     */
    ~ResFlat();

    /**
     * @brief Displays information about the residential flat.
     */
    void displayBuildingInfo() override;

    /**
     * @brief Gets the capacity of the residential flat.
     * @return The maximum number of residents that can occupy the flat.
     */
    int getCapacity() const override;

    /**
     * @brief Sets the capacity of the residential flat.
     * @param capacity The maximum number of residents to set.
     */
    void setCapacity(int capacity) override;

    // Observer methods

    /**
     * @brief Calls utilities related to the residential flat.
     */
    void callUtilities(); ///< Call Utilities in Buildings

    /**
     * @brief Gets the operational state of the residential flat.
     * @return True if the flat is operational, false otherwise.
     */
    bool getState();

    /**
     * @brief Sets the operational state of the residential flat.
     * @param state The operational state to set.
     */
    void setState(bool state);

    /**
     * @brief Gets the type of residential building.
     * @return A string representing the type of building.
     */
    std::string getBuildingType();

    /**
     * @brief Notifies the residential flat that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    void notifyEmployeeLeft(Citizen *employee);

    /**
     * @brief Moves a resident into the residential flat.
     * @param resident Pointer to the Citizen to be moved in.
     * @return True if the resident was successfully moved in, false otherwise.
     */
    bool moveIn(Citizen *resident);

    /**
     * @brief Moves a resident out of the residential flat.
     * @param resident Pointer to the Citizen to be moved out.
     */
    void moveOut(Citizen *resident);

    int getElectricityUsage();
    int getWaterUsage();
    int getCurCitizenCount();

private:
    int capacity; ///< Maximum number of residents in the flat
    string type = "Residential Flat"; ///< Type of the building
    bool operational; ///< Operational state of the residential flat

    vector<Citizen *> residents; ///< List of residents in the flat

    // Resource costs
    int cost = 1000; ///< Construction cost of the flat
    int woodCost = 10; ///< Wood cost for construction
    int steelCost = 5; ///< Steel cost for construction
    int concreteCost = 5; ///< Concrete cost for construction

    int electricityUsage = 5; ///< Electricity usage of the flat
    int waterUsage = 5; ///< Water usage of the flat

    int popIncrease = 5; ///< Population increase from the flat
};

#endif // RESFLAT_H
