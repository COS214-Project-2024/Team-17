/**
 * @file UtilPowerPlants.h
 * @brief Header file for the UtilPowerPlants class which implements UtilPowerPlants.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilPowerPlants.h
 */
#ifndef UTILPOWERPLANTS_H
#define UTILPOWERPLANTS_H
#include "UtilityManager.h"
#include <string>
using namespace std;
/**
 * @class UtilPowerPlants
 * @brief ...
 */
class UtilPowerPlants: public UtilityManager {
private:
std::string type="Power Plant";
	bool operational;//Observer State
    // int capacity;
    
public:
	UtilPowerPlants();
	void startUtility();
	void update(Building* unit);
	std::string getType();
	bool isOperational();
	void shutDown();
	// void restart();

	// void generateElectricity(Building& building);
};

#endif
