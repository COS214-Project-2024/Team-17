/**
 * @file UtilWasteMan.h
 * @brief Header file for the UtilWasteMan class which implements UtilWasteMan.
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
 * @brief ...
 */
class UtilWasteMan: public UtilityManager {
    private :
	std::string type="Waste Dump";
	bool operational;//Observer State
    // int capacity;

	//Resources:
	static const int cost = BuildingRequirements::wasteManagementBuildCost;
	static const int woodCost = BuildingRequirements::wasteManagementWoodCost;
	static const int concreteCost = BuildingRequirements::wasteManagementConcreteCost;
	static const int steelCost = BuildingRequirements::wasteManagementSteelCost;

    
public:
	/**
     * @brief Constructor for UtilWasteMan.
     */
	UtilWasteMan();
	/**
     * @brief Starts the Waste System service
     */
	void startUtility();
	/**
 	* @brief Updates the operational state of the utility based on the building's current status.
	 *@param[in] unit Pointer to the Building object that notifies this utility.
	 */
	void update(Building* unit);
	/**
	 * @brief Returns the type of utility service
	 * @return string
	 */
	std::string getType();
	/**
	 * @brief Returns the operational status of the utility service
	 * @return bool
	 */
	bool isOperational();
	/**
	 * @brief Shuts down the Waste System service
	 */
	void shutDown();
};

#endif
