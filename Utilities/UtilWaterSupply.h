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
    UtilWaterSupply();
	void startUtility();
	void update(Building* unit);
	std::string getType();
	bool isOperational();
	void shutDown();
    //void checkWayerSupply();
};

#endif
