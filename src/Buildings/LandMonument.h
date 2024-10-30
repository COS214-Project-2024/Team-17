#ifndef LANDMONUMENT_H
#define LANDMONUMENT_H

#include "Landmark.h"

class LandMonument : public Landmark {
public:
    LandMonument();

    void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;

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
	string type="Landmark Monument";
	bool operational;//CS State
};

#endif
