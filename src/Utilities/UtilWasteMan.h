/**
 * @file UtilWasteMan.h
 * @brief Header file for the UtilWasteMan class, implementing waste management services.
 * @details Contains the declaration of the UtilWasteMan class, managing waste collection and disposal operations.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilWasteMan.h
 */
#ifndef UTILWASTEMAN_H
#define UTILWASTEMAN_H
#include "UtilityManager.h"
#include "../Buildings/BuildingRequirements.h"
#include <string>
using namespace std;
/**
 * @class UtilWasteMan
 * @brief Represents the waste management system.
 * @details Handles waste collection and disposal operations for buildings.
 */
class UtilWasteMan: public UtilityManager {
    private :
    std::string type = "Waste Dump"; ///< Type of utility
    bool operational; ///< Operational state of the Waste Management service
    // int capacity;

	//Resources:
	static const int cost = BuildingRequirements::wasteManagementBuildCost;
	static const int woodCost = BuildingRequirements::wasteManagementWoodCost;
	static const int concreteCost = BuildingRequirements::wasteManagementConcreteCost;
	static const int steelCost = BuildingRequirements::wasteManagementSteelCost;

    
public:
    /**
     * @brief Constructs a new Waste Management utility.
     */
	UtilWasteMan();
    /**
     * @brief Starts the Waste Management service, making it operational.
     */
	void startUtility();
    /**
     * @brief Updates the operational state based on the status of the specified building.
     * @param[in] unit Pointer to the Building object that notifies this utility.
     */
	void update(Building* unit);
    /**
     * @brief Retrieves the type of this utility.
     * @return The type as a string ("Waste Dump").
     */
	std::string getType();
    /**
     * @brief Checks if the Waste Management service is operational.
     * @return True if operational; otherwise, false.
     */
	bool isOperational();
    /**
     * @brief Shuts down the Waste Management service, making it non-operational.
     */
	void shutDown();
};

#endif
