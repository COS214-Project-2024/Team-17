/**
 * @file UtilityManager.h
 * @brief Header file for the UtilityManager class which implements UtilityManager.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilityManager.h
 */
#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H
#include <vector>
#include <string>
#include "Building.h"
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
	std::string type;
	bool operational;//observer state

public:
    /**
     * @brief Starts the utility service
     */
	virtual void startUtility() = 0;
	/**
 	* @brief Updates the operational state of the utility based on the building's current status.
	 * @param[in] unit Pointer to the Building object that notifies this utility.
	 */
	virtual void update(Building* unit)=0;
	/**
	 * @brief Returns the type of utility service
	 * @return string
	 */
	virtual std::string getType()=0;
	/**
	 * @brief Returns the operational status of the utility service
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
