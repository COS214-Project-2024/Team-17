/**
 * @file UtilWasteMan.h
 * @brief Header file for the UtilWasteMan class which implements UtilWasteMan.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilWasteMan.h
 */
#ifndef UTILWASTEMAN_H
#define UTILWASTEMAN_H
#include "UtilityManager.h"
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
    
public:
	UtilWasteMan();
	void startUtility();
	void update(Building* unit);
	std::string getType();
	bool isOperational();
	void shutDown();
};

#endif
