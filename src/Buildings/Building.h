#ifndef BUILDING_H
#define BUILDING_H

#include "../../colours.h" // Testing colours and other includes
#include "../Utilities/UtilityManager.h"
#include "../Citizens/CityMediator.h"
#include "../Citizens/CityBlock.h"

#include "../Citizens/Citizen.h"

#include "../resources.h"
#include "BuildingRequirements.h"

class CityMediator;
class UtilityManager;
/**
 * @class Building
 * @brief Abstract base class representing a building in the city.
 *
 * This class defines the interface for all buildings, including 
 * properties and behaviors such as employee management, state 
 * checking, and coordinate handling. It serves as a base class 
 * for specific building types (e.g., residential, commercial).
 */
class Building : public CityBlock
{
public:
    /**
     * @brief Constructs a Building with an optional type.
     * @param type The type of the building (default is an empty string).
     */
    Building(string type = "");

    /**
     * @brief Displays information about the building.
     * This method is pure virtual and must be implemented by derived classes.
     */
    virtual void displayBuildingInfo() = 0;

    /**
     * @brief Destructor for the Building class.
     */
    virtual ~Building() = default;

    /**
     * @brief Gets the operational state of the building.
     * @return True if the building is operational, otherwise false.
     */
    virtual bool getState() = 0;

    /**
     * @brief Gets the type of the building.
     * @return The type of the building as a string.
     */
    virtual string getBuildingType();

    /**
     * @brief Checks if the building meets construction requirements.
     * @return True if requirements are met, otherwise false.
     */
    virtual bool checkBuildRequirements() = 0;

    /**
     * @brief Notifies changes to the building state or status.
     * @param message The message describing the change.
     */
    void notifyChange(std::string message);

    // Uncomment if using the visitor pattern.
    // void accept(TaxAndBudgetVisitor *visitor);

    /**
     * @brief Gets the X coordinate of the building.
     * @return The X coordinate.
     */
    int getXCoordinate();

    /**
     * @brief Gets the Y coordinate of the building.
     * @return The Y coordinate.
     */
    int getYCoordinate();

    /**
     * @brief Sets the X coordinate of the building.
     * @param x The new X coordinate.
     */
    void setXCoordinate(int x);

    /**
     * @brief Sets the Y coordinate of the building.
     * @param y The new Y coordinate.
     */
    void setYCoordinate(int y);

    /**
     * @brief Adds an employee to the building.
     * @param employee Pointer to the Citizen object representing the employee.
     * @return True if the employee is added successfully, otherwise false.
     */
    virtual bool addEmployee(Citizen *employee) = 0;

    /**
     * @brief Removes an employee from the building.
     * @param employee Pointer to the Citizen object representing the employee.
     */
    virtual void removeEmployee(Citizen *employee) = 0;

    /**
     * @brief Notifies that an employee has left the building.
     * @param employee Pointer to the Citizen object representing the employee.
     */
    virtual void notifyEmployeeLeft(Citizen *employee) = 0;

    /**
     * @brief Checks if there are jobs available in the building.
     * @return True if jobs are available, otherwise false.
     */
    virtual bool hasJob() = 0;

    /**
     * @brief Moves a resident into the building.
     * @param resident Pointer to the Citizen object representing the resident.
     * @return True if the move is successful, otherwise false.
     */
    virtual bool moveIn(Citizen *resident) = 0;

    /**
     * @brief Moves a resident out of the building.
     * @param resident Pointer to the Citizen object representing the resident.
     */
    virtual void moveOut(Citizen *resident) = 0;

private:
    vector<UtilityManager *> utilities; ///< List of utility managers associated with the building.
    string name; ///< Name of the building.
    CityMediator *mediator; ///< Mediator for communication between buildings and city.
    bool operational; ///< Operational state of the building.

    // Coordinates:
    int xCoordinate; ///< X coordinate of the building.
    int yCoordinate; ///< Y coordinate of the building.
};

#endif // BUILDING_H

////// EVERYTHING BELOW IS FROM VP - IT IS SUBJECT TO CHANGE //////

// #ifndef BUILDING_H
// #define BUILDING_H

// class Building : UtilityObserver, CityBlock {

// private:
// 	string name;
// 	CityMediator* mediator;

// 	virtual bool checkBuildRequirements() = 0;

// public:
// 	virtual void createBuilding() = 0;

// 	void update(string& utilityStatus);

// 	void receiveElectricity();

// 	void receiveWater();

// 	void removeWaste();

// 	void removeSewage();

// 	void notifyOutage(string& utility);

// 	void notifyNoWater(string& utility);

// 	void notifyWasteRemove(string& utility);

// 	void notifySewageRemove(string& utility);

// 	virtual void affectEmotionalState() = 0;

// 	Building(CityMediator* mediator, string type);

// 	string getType();

// 	void construct();

// 	void abstract_notifyChange();

// 	void accept(TaxAndBudgetVisitor* visitor);
// };

// #endif
