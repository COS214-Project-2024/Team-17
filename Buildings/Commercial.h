#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include <iostream>
class Commercial : public Building {
	private:
	bool operational;//CS State
	std::string type;
	// int jobCapacity;?
public:
	virtual int getJobCapacity() = 0;
	virtual void setJobCapacity(int capacity) = 0;
	// virtual void update(UtilityManager* unit);
//Observer
	// idk if this should be pure virt bc supposed to be concrete subject XD
	virtual void callUtilities();//call Utilities in Buildings
	virtual bool getState();
	virtual void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	virtual std::string getBuildingType();
	
	
	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif
