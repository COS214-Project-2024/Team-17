#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include "../Utilities/UtilityManager.h"
#include <vector>
#include <iostream>
class UtilityManager;
class Residential : public Building {
	private:
    bool operational;//state
    std::vector<UtilityManager*> Utilities;
public:
	virtual int getCapacity() const = 0;
	virtual void setCapacity(int capacity) = 0;
//Observer
    virtual bool getState()=0;
    virtual std::string getBuildingType()=0;
    void addUtility(UtilityManager* utility);//attach
    void removeUtility(UtilityManager* utility);//detach
    void notifyUtilities();//notify

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
};

#endif // RESIDENTIAL_H