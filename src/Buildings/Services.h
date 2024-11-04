#ifndef SERVICES_H
#define SERVICES_H

#include "Building.h"
// class UtilityManager;
/**
 * @class Services
 * @brief Abstract base class representing a service building.
 *
 * This class serves as a base for all service types, providing
 * functionality to manage citizens, utilities, and operational state.
 */
class Services : public Building
{
public:
    /**
     * @brief Constructs a Services object.
     * @param citizensServed The number of citizens this service can accommodate.
     */
	Services(int citizensServed);
	    /**
     * @brief Pure virtual function to get the number of visitors.
     * @return The number of visitors currently in the service.
     */
	virtual int getVisitors() = 0;
	    /**
     * @brief Pure virtual function to set the number of visitors.
     * @param visitors The number of visitors to set.
     */
	virtual void setVisitors(int visitors) = 0;
    /**
     * @brief Checks if the building meets the necessary requirements for construction.
     * @return True if the requirements are met, false otherwise.
     */
	bool checkBuildRequirements() override;

	// Observer

	    /**
     * @brief Pure virtual function to get the operational state of the service.
     * @return True if the service is operational, false otherwise.
     */
	virtual bool getState() = 0;
	    /**
     * @brief Pure virtual function to get the type of building.
     * @return A string representing the type of building.
     */
	virtual std::string getBuildingType() = 0;
    /**
     * @brief Attaches a utility manager to the service.
     * @param utility Pointer to the UtilityManager to be attached.
     */
	void addUtility(UtilityManager *utility);	 // attach

    /**
     * @brief Detaches a utility manager from the service.
     * @param utility Pointer to the UtilityManager to be detached.
     */
	void removeUtility(UtilityManager *utility); // detach
    /**
     * @brief Notifies all attached utilities of a change in state.
     */
	void notifyUtilities();						 // notify

    /**
     * @brief Pure virtual function to add an employee to the service.
     * @param employee Pointer to the Citizen to be added as an employee.
     * @return True if the employee was added successfully, false otherwise.
     */
	virtual bool addEmployee(Citizen *employee) = 0;
    /**
     * @brief Pure virtual function to remove an employee from the service.
     * @param employee Pointer to the Citizen to be removed.
     */
	virtual void removeEmployee(Citizen *employee) = 0;
    /**
     * @brief Notifies the service that an employee has left.
     * @param employee Pointer to the Citizen who has left.
     */
	virtual void notifyEmployeeLeft(Citizen *employee) = 0;

    /**
     * @brief Moves a resident into the service.
     * @param resident Pointer to the Citizen moving in.
     * @return True if the resident moved in successfully, false otherwise.
     */
	virtual bool moveIn(Citizen *resident);
	/**
     * @brief Moves a resident out of the service.
     * @param resident Pointer to the Citizen moving out.
     */
	virtual void moveOut(Citizen *resident);

	virtual int getElectricityUsage() = 0;
    virtual int getWaterUsage() = 0;
    virtual int getCurCitizenCount() = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual void createBuilding() = 0;
	// virtual void affectEmotionalState() = 0;
	/**
     * @brief Gets the number of citizens served by this service.
     * @return The number of citizens served.
     */
	int getCitizenServed();

private:
	bool operational; // part of Observer
	vector<UtilityManager *> Utilities;
	int citizensServed;
};

#endif
