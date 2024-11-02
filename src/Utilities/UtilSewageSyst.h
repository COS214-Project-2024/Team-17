/**
/**
 * @file UtilSewageSyst.h
 * @brief Header file for the UtilSewageSyst class, implementing sewage system services.
 * @details Contains the declaration of the UtilSewageSyst class, managing operations related to sewage disposal.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilSewageSyst.h
 */
#ifndef UTILSEWAGESYST_H
#define UTILSEWAGESYST_H
#include "UtilityManager.h"
#include "../Buildings/BuildingRequirements.h"
#include <string>
using namespace std;
/**
 * @class UtilSewageSyst
 * @brief Represents the sewage management system.
 * @details Handles sewage disposal operations for buildings.
 */
class UtilSewageSyst: public UtilityManager {
        private :
	std::string type="Sewage System";
	bool operational;//Observer State

	//Resources:
	static const int cost = BuildingRequirements::sewageSystemBuildCost;
	static const int woodCost = BuildingRequirements::sewageSystemWoodCost;
	static const int concreteCost = BuildingRequirements::sewageSystemConcreteCost;
	static const int steelCost = BuildingRequirements::sewageSystemSteelCost;
    
public:
    /**
     * @brief Constructs a new Sewage System utility.
     */
	UtilSewageSyst();
    /**
     * @brief Starts the Sewage System service, making it operational.
     */
	void startUtility();
    /**
     * @brief Updates the operational state based on the status of the specified building.
     * @param[in] unit Pointer to the Building object that notifies this utility.
     */
	void update(Building* unit);
    /**
     * @brief Retrieves the type of this utility.
     * @return The type as a string ("Sewage System").
     */
	std::string getType();
    /**
     * @brief Checks if the Sewage System is operational.
     * @return True if operational; otherwise, false.
     */
	bool isOperational();
    /**
     * @brief Shuts down the Sewage System, making it non-operational.
     */
	void shutDown();
};

#endif
