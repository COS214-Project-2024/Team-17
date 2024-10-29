#ifndef LANDPARK_H
#define LANDPARK_H

#include "Landmark.h"

class LandPark : public Landmark {
public:
    LandPark();

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
	std::string getBuildingType();

	// bool checkBuildRequirements() override;
	// void createBuilding() override;
	// void affectEmotionalState() override;

private:
	int visitors;
	string type="Landmark Park";
	bool operational;//CS State
};

#endif
