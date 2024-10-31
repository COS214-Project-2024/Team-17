/**
 * @file UtilSewageSyst.h
 * @brief Header file for the UtilSewageSyst class which implements UtilSewageSyst.
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
 * @brief ...
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
     * @brief Constructor for UtilSewageSyst.
     */
	UtilSewageSyst();
	/**
     * @brief Starts the Sweage System service
     */
	void startUtility();
	/**
 	* @brief Updates the operational state of the utility based on the building's current status.
	* @param[in] unit Pointer to the Building object that notifies this utility.
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
	 * @brief Shuts down the Sewage System service
	 */
	void shutDown();
};

#endif
