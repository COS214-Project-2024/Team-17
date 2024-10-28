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
 * @brief ...
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
	virtual void startUtility() = 0;
	virtual void update(Building* unit)=0;
	virtual std::string getType()=0;
	virtual bool isOperational()=0;
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
