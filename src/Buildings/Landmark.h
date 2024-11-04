#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"
// class UtilityManager;
/**
 * @class Landmark
 * @brief Abstract class representing a landmark building.
 *
 * The Landmark class inherits from the Building class and serves as a base class
 * for different types of landmarks, providing a common interface for visitor management,
 * utility management, and employee handling.
 */
class Landmark : public Building
{
public:
    /**
     * @brief Gets the number of visitors currently in the landmark.
     * @return The number of visitors.
     */
    virtual int getVisitors() = 0;

    /**
     * @brief Sets the number of visitors in the landmark.
     * @param visitors The number of visitors to set.
     */
    virtual void setVisitors(int visitors) = 0;

    /**
     * @brief Checks if the building meets the requirements for construction.
     * @return True if build requirements are met, false otherwise.
     */
    bool checkBuildRequirements() override;

    // Observer methods

    /**
     * @brief Gets the operational state of the landmark.
     * @return True if the landmark is operational, false otherwise.
     */
    virtual bool getState();

    /**
     * @brief Gets the type of building.
     * @return A string representing the building type.
     */
    virtual std::string getBuildingType();

    /**
     * @brief Attaches a utility manager to the landmark.
     * @param utility Pointer to the UtilityManager to attach.
     */
    void addUtility(UtilityManager *utility);    ///< Attach a utility manager

    /**
     * @brief Detaches a utility manager from the landmark.
     * @param utility Pointer to the UtilityManager to detach.
     */
    void removeUtility(UtilityManager *utility); ///< Detach a utility manager

    /**
     * @brief Notifies all attached utility managers of changes.
     */
    void notifyUtilities();                       ///< Notify all utility managers

    /**
     * @brief Adds an employee to the landmark.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was successfully added, false otherwise.
     */
    virtual bool addEmployee(Citizen *employee) = 0;

    /**
     * @brief Removes an employee from the landmark.
     * @param employee Pointer to the Citizen to be removed as an employee.
     */
    virtual void removeEmployee(Citizen *employee) = 0;

    /**
     * @brief Notifies the landmark that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
    virtual void notifyEmployeeLeft(Citizen *employee) = 0;

    /**
     * @brief Moves a resident into the landmark.
     * @param resident Pointer to the Citizen moving in.
     * @return True if the move was successful, false otherwise.
     */
    virtual bool moveIn(Citizen *resident);

    /**
     * @brief Moves a resident out of the landmark.
     * @param resident Pointer to the Citizen moving out.
     */
    virtual void moveOut(Citizen *resident);

    // Optional methods to be implemented by derived classes
    // virtual bool checkBuildRequirements() = 0;
    // virtual void createBuilding() = 0;
    // virtual void affectEmotionalState() = 0;

private:
    int visitors; ///< Current number of visitors in the landmark
    bool operational; ///< Operational state of the landmark
    vector<UtilityManager *> Utilities; ///< List of attached utility managers
};

#endif // LANDMARK_H
