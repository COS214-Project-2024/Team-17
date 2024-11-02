/**
 * @file UtilityManager.h
 * @brief Header file for the UtilityManager class, which serves as an abstract base class for utility services.
 * @details This file defines the abstract UtilityManager class, which represents the base functionality
 * for various utility services in a city system. Specific utilities like power, water, waste, and sewage management
 * inherit from this class and implement the start, update, and shutdown mechanisms.
 * @author WORKONMYMACHINE TEAM Nic
 */
#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H
#include <vector>
#include <string>
#include "../Buildings/Building.h"
using namespace std;

class Building;
/**
 * @class UtilityManager
 * @brief Abstract base class for all concrete utilities in the system
 */
class UtilityManager{

private:
// vector<Building*> Buildings;
	// UtilPowerPlants powerPlant;
	// UtilWaterSupply waterSupply;
	// UtilWasteMan wasteManagement;
	// UtilSewageSyst sewageSystem;
	// CityMediator* mediator;
	string type;
	bool operational;//observer state

public:
    /**
     * @brief Starts the utility service
     */
	virtual void startUtility() = 0;
	/**
     * @brief Updates the operational state of the utility based on a building's status.
     * @param[in] unit Pointer to the Building object notifying this utility of a change.
    */
	virtual void update(Building* unit)=0;
	/**
	 * @brief Returns the type of utility service
	 * @return string
	 */
	virtual string getType()=0;
	/**
	 * @brief Checks if the utility service is operational.
	 * @return bool
	 */
	virtual bool isOperational()=0;
	/**
	 * @brief Shuts down the utility service
	 */
	virtual void shutDown()=0;
	// virtual void restart()=0;
	

	// virtual bool getState()=0;
	// void addDevice(Building* device);

	// void removeDevice(Building* device);

	// void notifyDevices();



	// void supplyElectricity(Building& building);

	// void provideWater(Building& building);

	// void manageWaste(Building& building);

	// void manageSewage(Building& building);

	// void updateUtilities(Building& building);

	// virtual void addObserver(Building* observer) = 0;

	// virtual void removeObserver(Building* observer) = 0;

	// virtual void notifyObservers() = 0;

	// // void Utilities(CityMediator* mediator);

	// void abstract_notifyChange();
};

#endif
