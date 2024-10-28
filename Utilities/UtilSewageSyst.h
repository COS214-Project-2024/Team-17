/**
 * @file UtilSewageSyst.h
 * @brief Header file for the UtilSewageSyst class which implements UtilSewageSyst.
 * @author WORKONMYMACHINE TEAM Nic
 * @headerfile UtilSewageSyst.h
 */
#ifndef UTILSEWAGESYST_H
#define UTILSEWAGESYST_H
#include "UtilityManager.h"
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
    
public:
	// string state;
	UtilSewageSyst();
	void startUtility();
	void update(Building* unit);
	std::string getType();
	bool isOperational();
	void shutDown();
};

#endif
