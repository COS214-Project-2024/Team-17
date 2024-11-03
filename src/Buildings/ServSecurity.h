#ifndef SERVSECURITY_H
#define SERVSECURITY_H

#include "Services.h"

class ServSecurity : public Services
{
public:
	ServSecurity();
	~ServSecurity();

	void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// Observer
	void callUtilities(); // call Utilities in Buildings
	bool getState();
	void setState(bool state);

	std::string getBuildingType();

	// Resources
	bool addEmployee(Citizen *employee);
	void removeEmployee(Citizen *employee);
	void notifyEmployeeLeft(Citizen *employee);
	bool hasJob();

private:
	int visitors;
	bool operational; // CS State
	string type = "Service Security";

	// Resources
	vector<Citizen *> employees;
	int cost = 1500;

	int woodCost = 5;
	int steelCost = 10;
	int concreteCost = 15;

	int electricityUsage = 10;
	int waterUsage = 15;

	int happinessIncrease = 5;
	int jobCapacity = 10;
	int cityIncome = 50;
};

#endif
