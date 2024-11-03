#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"

class Landmark : public Building {
public:
	virtual int getVisitors() = 0;
	virtual void setVisitors(int visitors) = 0;

	bool checkBuildRequirements() override;

	//Observer
    virtual bool getState();
    virtual std::string getBuildingType();
    void addUtility(UtilityManager* utility);//attach
    void removeUtility(UtilityManager* utility);//detach
    void notifyUtilities();//notify

	virtual int getElectricityUsage() = 0;
	virtual int getWaterUsage() = 0;
	virtual int getCurCitizenCount() = 0;

	// virtual bool checkBuildRequirements() = 0;
	// virtual void createBuilding() = 0;
	// virtual void affectEmotionalState() = 0;

private:
	int visitors;
    bool operational;//state
    vector<UtilityManager*> Utilities;

};

#endif
