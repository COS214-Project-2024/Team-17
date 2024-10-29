#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"

class UtilityManager;

class Industrial : public Building {
public:
	virtual int getProductionCapacity() = 0;
	virtual void setProductionCapacity(int capacity) = 0;

	bool checkBuildRequirements() override;

	// Observer pattern
    virtual bool getState();
    virtual std::string getBuildingType();
    void addUtility(UtilityManager* utility);//attach
    void removeUtility(UtilityManager* utility);//detach
    void notifyUtilities();//notify

	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
	bool operational;//state
    vector<UtilityManager*> Utilities;
};

#endif