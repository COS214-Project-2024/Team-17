#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include <iostream>
class Landmark : public Building {
	private:
	bool operational;//CS State
	std::string type;
	int visitors;

public:
	virtual int getVisitors() = 0;
	virtual void setVisitors(int visitors) = 0;
//Observer
	virtual void callUtilities();//call Utilities in Buildings
	virtual bool getState();
	virtual void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	virtual std::string getBuildingType();

	// virtual bool checkBuildRequirements() = 0;
	// virtual void createBuilding() = 0;
	// virtual void affectEmotionalState() = 0;

	
};

#endif
