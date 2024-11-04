/**
 * @file ServEducation.h
 * @brief Declares the ServEducation class for education service buildings.
 */
#ifndef SERVENTERTAINMENT_H
#define SERVENTERTAINMENT_H

#include "Services.h"
/**
 * @class ServEducation
 * @brief Represents an education service building.
 */
class ServEntertainment : public Services
{
public:
    /**
     * @brief Constructs an education service building.
     */
	ServEntertainment();
	    /**
     * @brief Destroys the education service building.
     */
	~ServEntertainment();
    /**
     * @brief Displays information about the building.
     */
	void displayBuildingInfo() override;
    /**
     * @brief Gets the current number of visitors.
     * @return The number of visitors.
     */
	int getVisitors() override;
    /**
     * @brief Sets the number of visitors.
     * @param visitors The number of visitors to set.
     */
	void setVisitors(int visitors) override;

	// Observer
	/**
	 * @brief Calls associated utility managers for the building.
	 */
	void callUtilities(); // call Utilities in Buildings
	/**
	 * @brief Gets the operational state of the building.
	 * @return True if operational, false otherwise.
	 */
	bool getState();
	/**
	 * @brief Sets the operational state of the building.
	 * @param state The operational state to set.
	 */
	void setState(bool state);
	/**
	 * @brief Gets the building type as a string.
	 * @return The building type.
	 */
	string getBuildingType();

	// Resources
	/**
	 * @brief Adds an employee to the building.
	 * @param employee The employee to add.
	 * @return True if the employee was added, false otherwise.
	 */
	bool addEmployee(Citizen *employee);
	/**
	 * @brief Removes an employee from the building.
	 * @param employee The employee to remove.
	 */
	void removeEmployee(Citizen *employee);
	/**
	 * @brief Notifies when an employee has left.
	 * @param employee Pointer to the employee who left.
	 */
	void notifyEmployeeLeft(Citizen *employee);
	
	/**
	 * @brief Checks if the building has a job.
	 * @return True if the building has a job, false otherwise.
	 */
	bool hasJob();

private:
	int visitors;
	string type = "Service Entertainment";
	bool operational; // CS State

	// Resources
	vector<Citizen *> employees;
	int cost = 2000;

	int woodCost = 10;
	int steelCost = 10;
	int concreteCost = 15;

	int electricityUsage = 15;
	int waterUsage = 15;

	int happinessIncrease = 10;
	int jobCapacity = 10;
	int cityIncome = 100;
};

#endif
