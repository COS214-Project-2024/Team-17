#ifndef LANDCCENTER_H
#define LANDCCENTER_H

#include "Landmark.h"

class LandCCenter : public Landmark {
public:
    LandCCenter();

    void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;
	
	bool checkBuildRequirements() override;

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	string getBuildingType();

	// bool checkBuildRequirements() override;
	// void createBuilding() override;
	// void affectEmotionalState() override;

private:
	int visitors;
	string type="Landmark Community Center";
	bool operational;//CS State
};

#endif
