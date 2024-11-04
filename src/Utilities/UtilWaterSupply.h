/**
 * @file UtilWaterSupply.h
 * @brief Header file for the UtilWaterSupply class, implementing water supply services.
 * @details Contains the declaration of the UtilWaterSupply class, managing water distribution to buildings.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilWaterSupply.h
 */
#ifndef UTILWATERSUPPLY_H
#define UTILWATERSUPPLY_H
#include "UtilityManager.h"
#include "../Buildings/BuildingRequirements.h"
#include <iostream>
#include <string>
using namespace std;
/**
 * @class UtilWaterSupply
 * @brief Represents the water supply system.
 * @details Manages water distribution operations to ensure a consistent supply to buildings.
 */
class UtilWaterSupply: public UtilityManager {
private :
    std::string type = "Water Supply"; ///< Type of utility
    bool operational; ///< Operational state of the Water Supply service
    // int capacity;

    //Resources:
    static const int cost = BuildingRequirements::waterSupplyBuildCost;
    static const int woodCost = BuildingRequirements::waterSupplyWoodCost;
    static const int concreteCost = BuildingRequirements::waterSupplyConcreteCost;
    static const int steelCost = BuildingRequirements::waterSupplySteelCost;
    
public:
    /**
     * @brief Constructs a new Water Supply utility.
     */
    UtilWaterSupply();
    /**
     * @brief Starts the Water Supply service, making it operational.
     */
	void startUtility();
    /**
     * @brief Updates the operational state based on the status of the specified building.
     * @param[in] unit Pointer to the Building object that notifies this utility.
     */
	void update(Building* unit);
    /**
     * @brief Retrieves the type of this utility.
     * @return The type as a string ("Water Supply").
     */
	std::string getType();
    /**
     * @brief Checks if the Water Supply service is operational.
     * @return True if operational; otherwise, false.
     */
	bool isOperational();
    /**
     * @brief Shuts down the Water Supply service, making it non-operational.
     */
	void shutDown();
    //void checkWayerSupply();
};

#endif
