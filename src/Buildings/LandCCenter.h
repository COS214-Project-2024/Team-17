#ifndef LANDCCENTER_H
#define LANDCCENTER_H

#include "Landmark.h"

class LandCCenter : public Landmark
{
public:
	LandCCenter();
	~LandCCenter();

	void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;

	bool checkBuildRequirements() override;

	// Observer
	void callUtilities(); // call Utilities in Buildings
	bool getState();
	void setState(bool state);

	string getBuildingType();

	bool addEmployee(Citizen *employee);
	void removeEmployee(Citizen *employee);
	void notifyEmployeeLeft(Citizen *employee);
	bool hasJob();

private:
	vector<Citizen *> employees;

	// Resources

	int cost = 2000;

	int jobCapacity = 10;

	int woodCost = 20;
	int concreteCost = 30;
	int steelCost = 15;

	int electricityUsage = 5;
	int waterUsage = 10;

	int happiness = 15;

	int visitors;
	string type = "Landmark Community Center";
	bool operational; // CS State
};

#endif
