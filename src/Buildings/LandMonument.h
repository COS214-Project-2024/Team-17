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

	void addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);

private:
	vector<Citizen*> employees;

	//Resources

	int cost = 1500;

    int jobCapacity = 10;
	
	int woodCost = 10;
	int concreteCost = 20;
	int steelCost = 10;

	int electricityUsage = 5;
	int waterUsage = 10;

	int happiness = 10;


	int visitors;
	string type="Landmark Monument";
	bool operational;//CS State
};

#endif
