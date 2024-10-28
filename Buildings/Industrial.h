#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include <iostream>
class Industrial : public Building {
	private:
	bool operational;//CS State
	std::string type;
public:
	virtual int getProductionCapacity() = 0;
	virtual void setProductionCapacity(int capacity) = 0;
//Observer
	virtual void callUtilities();//call Utilities in Buildings
	virtual bool getState();
	virtual void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	virtual std::string getBuildingType();

	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif