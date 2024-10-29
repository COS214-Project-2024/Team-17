#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"
#include <vector>
#include <iostream>
class UtilityManager;
class Landmark : public Building {
	private:
    bool operational;//state
    std::vector<UtilityManager*> Utilities;
	int visitors;

public:
	virtual int getVisitors() = 0;
	virtual void setVisitors(int visitors) = 0;
//Observer
    virtual bool getState()=0;
    virtual std::string getBuildingType()=0;
    void addUtility(UtilityManager* utility);//attach
    void removeUtility(UtilityManager* utility);//detach
    void notifyUtilities();//notify

	// virtual bool checkBuildRequirements() = 0;
	// virtual void createBuilding() = 0;
	// virtual void affectEmotionalState() = 0;

	
};

#endif
