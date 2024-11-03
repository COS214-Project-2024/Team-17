#ifndef SERVICES_H
#define SERVICES_H

#include "Building.h"

class Services : public Building {
public:
	virtual int getVisitors() = 0;
	virtual void setVisitors(int visitors) = 0;

	bool checkBuildRequirements() override;

	//Observer
    virtual bool getState()=0;
    virtual std::string getBuildingType()=0;
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
	bool operational; // part of Observer
	vector<UtilityManager*> Utilities;
};

#endif
