#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"
#include <vector>
#include <iostream>
class UtilityManager;
class Industrial : public Building {
	private:
    bool operational;//state
    std::vector<UtilityManager*> Utilities;
public:
	virtual int getProductionCapacity() = 0;
	virtual void setProductionCapacity(int capacity) = 0;
//Observer
    virtual bool getState()=0;
    virtual std::string getBuildingType()=0;
    void addUtility(UtilityManager* utility);//attach
    void removeUtility(UtilityManager* utility);//detach
    void notifyUtilities();//notify
	
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif