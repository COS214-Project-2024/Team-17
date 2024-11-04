#ifndef INDFACTORY_H
#define INDFACTORY_H

#include "Industrial.h"

class IndFactory : public Industrial
{
public:
	IndFactory();
	~IndFactory();

	void displayBuildingInfo() override;

	int getProductionCapacity() override;
	void setProductionCapacity(int capacity) override;

	// Observer
	void callUtilities();
	bool getState();
	void setState(bool state);

	string getBuildingType() override;

	bool addEmployee(Citizen *employee);
	void removeEmployee(Citizen *employee);
	void notifyEmployeeLeft(Citizen *employee);
	bool hasJob();

	int getElectricityUsage();
    int getWaterUsage();
    int getCurCitizenCount();

private:
	vector<Citizen *> employees;

	// Resources

	int cost = 1500;

	int jobCapacity = 10;

	int woodCost = 20;
	int concreteCost = 10;
	int steelCost = 10;

	int electricityUsage = 10;
	int waterUsage = 5;

	int woodProduction = 5;

	string type = "Industrial Factory";
	bool operational; // CS State
};

#endif
