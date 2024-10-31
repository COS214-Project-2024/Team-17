/**
 * @file UtilPowerPlants.h
 * @brief Header file for the UtilPowerPlants class which implements UtilPowerPlants.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilPowerPlants.h
 */
#ifndef UTILPOWERPLANTS_H
#define UTILPOWERPLANTS_H
#include "UtilityManager.h"
#include "../Buildings/BuildingRequirements.h"
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

	//Resources:
	static const int cost = BuildingRequirements::powerPlantBuildCost;
	static const int woodCost = BuildingRequirements::powerPlantWoodCost;
	static const int concreteCost = BuildingRequirements::powerPlantConcreteCost;
	static const int steelCost = BuildingRequirements::powerPlantSteelCost;
	
    
public:
	/**
     * @brief Constructor for UtilPowerPlants.
     */
	UtilPowerPlants();
	/**
     * @brief Starts the Power Plant service
     */
	void startUtility();
	/**
 	* @brief Updates the operational state of the utility based on the building's current status.
	 *@param[in] unit Pointer to the Building object that notifies this utility.
	 */
	void update(Building* unit);
	/**
	 * @brief Returns the type of utility service (Power Plant)
	 * @return string
	 */
	std::string getType();
	/**
	 * @brief Returns the operational status of the Power Plant service
	 * @return bool
	 */
	bool isOperational();
	/**
	 * @brief Shuts down the Power Plant service
	 */
	void shutDown();
	// void restart();

	// void generateElectricity(Building& building);
};

#endif
