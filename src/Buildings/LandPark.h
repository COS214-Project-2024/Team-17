#ifndef LANDPARK_H
#define LANDPARK_H

#include "Landmark.h"

class LandPark : public Landmark
{
public:
	LandPark();
	~LandPark();

	void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// Observer
	void callUtilities(); // call Utilities in Buildings
	bool getState();
	void setState(bool state);

	std::string getBuildingType();

	bool addEmployee(Citizen *employee);
	void removeEmployee(Citizen *employee);
	void notifyEmployeeLeft(Citizen *employee);
	bool hasJob();

private:
	vector<Citizen *> employees;

	// Resources

	int cost = 1000;

	int jobCapacity = 10;

	int woodCost = 25;
	int concreteCost = 5;
	int steelCost = 10;

	int electricityUsage = 5;
	int waterUsage = 10;

	int happiness = 5;

	int visitors;
	string type = "Landmark Park";
	bool operational; // CS State
};

#endif
