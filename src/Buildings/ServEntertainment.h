#ifndef SERVENTERTAINMENT_H
#define SERVENTERTAINMENT_H

#include "Services.h"

class ServEntertainment : public Services
{
public:
	ServEntertainment();
	~ServEntertainment();

	void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// Observer
	void callUtilities(); // call Utilities in Buildings
	bool getState();
	void setState(bool state);

	string getBuildingType();

	// Resources
	bool addEmployee(Citizen *employee);
	void removeEmployee(Citizen *employee);
	void notifyEmployeeLeft(Citizen *employee);
	bool hasJob();

	int getElectricityUsage();
    int getWaterUsage();
    int getCurCitizenCount();

private:
	int visitors;
	string type = "Service Entertainment";
	bool operational; // CS State

	// Resources
	vector<Citizen *> employees;
	int cost = 2000;

	int woodCost = 10;
	int steelCost = 10;
	int concreteCost = 15;

	int electricityUsage = 15;
	int waterUsage = 15;

	int happinessIncrease = 10;
	int jobCapacity = 10;
	int cityIncome = 100;
};

#endif
