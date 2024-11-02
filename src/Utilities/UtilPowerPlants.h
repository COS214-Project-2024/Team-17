/**
 * @file UtilPowerPlants.h
 * @brief Header file for the UtilPowerPlants class which implements the Power Plant utility system.
 * @details This file contains the declaration of the UtilPowerPlants class, which manages operations for the Power Plant utility.
 * The Power Plant utility is responsible for managing electricity supply to buildings.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilPowerPlants.h
 */
#ifndef UTILPOWERPLANTS_H
#define UTILPOWERPLANTS_H
#include "UtilityManager.h"
#include "../Buildings/BuildingRequirements.h"
#include <string>

/**
 * @class UtilPowerPlants
 * @brief Represents the Power Plant utility within the system.
 * @details Inherits from UtilityManager and provides specific functionality for managing power supply.
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
     * @brief Constructs a new Power Plant utility.
     */
	UtilPowerPlants();
    /**
     * @brief Starts the Power Plant service, making it operational.
     */
	void startUtility();
    /**
     * @brief Updates the operational state based on the status of the specified building.
     * @param[in] unit Pointer to the Building object that notifies this utility.
     */
	void update(Building* unit);
    /**
     * @brief Retrieves the type of this utility.
     * @return The type as a string ("Power Plant").
     */
	std::string getType();
    /**
     * @brief Checks if the Power Plant is operational.
     * @return True if operational; otherwise, false.
     */
	bool isOperational();
    /**
     * @brief Shuts down the Power Plant, making it non-operational.
     */
	void shutDown();
	// void restart();

	// void generateElectricity(Building& building);
};

#endif
