/**
 * @file UtilWaterSupply.h
 * @brief Header file for the UtilWaterSupply class which implements UtilWaterSupply.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilWaterSupply.h
 */
#ifndef UTILWATERSUPPLY_H
#define UTILWATERSUPPLY_H
#include "UtilityManager.h"
#include <iostream>
#include <string>
using namespace std;
/**
 * @class UtilWaterSupply
 * @brief ...
 */
class UtilWaterSupply: public UtilityManager {
private :
	std::string type="Water Supply";
	bool operational;//Observer State
    // int capacity;
    
public:
    /**
     * @brief Constructor for UtilWaterSupply.
     */
    UtilWaterSupply();
    /**
     * @brief Starts the Water Supply service
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
     * @brief Shuts down the Water Supply service
     */
	void shutDown();
    //void checkWayerSupply();
};

#endif
