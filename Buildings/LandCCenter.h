#ifndef LANDCCENTER_H
#define LANDCCENTER_H

#include "Landmark.h"
#include <iostream>
class LandCCenter : public Landmark {
public:
    LandCCenter();

    void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// bool checkBuildRequirements() override;
	// void createBuilding() override;
	// void affectEmotionalState() override;

//Observer
	void callUtilities()override;//call Utilities in Buildings
	bool getState()override;
	void setState(bool state)override;
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType()override;

private:
	int visitors;
	std::string type="Landmark Community Center";
	bool operational;//CS State
};

#endif
