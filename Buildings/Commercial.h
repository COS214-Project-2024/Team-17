#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"
#include <vector>
#include <iostream>
class UtilityManager;
class Commercial : public Building {
	private:
    // bool operational;//state
    std::vector<UtilityManager*> Utilities;
	// int jobCapacity;?
public:
	virtual int getJobCapacity() = 0;
	virtual void setJobCapacity(int capacity) = 0;
	// virtual void update(UtilityManager* unit);

//Observer
    virtual bool getState()=0;
    virtual std::string getBuildingType()=0;
    void addUtility(UtilityManager* utility);//attach
    void removeUtility(UtilityManager* utility);//detach
    void notifyUtilities();//notify
	
	
	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif
