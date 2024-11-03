#ifndef COMSHOP_H
#define COMSHOP_H

#include "Commercial.h"

class ComShop : public Commercial {
public:
    ComShop();
	~ComShop();

    void displayBuildingInfo() override;

	virtual int getJobCapacity() override;
	virtual void setJobCapacity(int capacity) override;

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);

	string getBuildingType()override;

	bool addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);
	
	int getElectricityUsage();
	int getWaterUsage();
	int getCurCitizenCount();

private:
	vector<Citizen*> employees;

	//Recources
	int cost = 1000;

    int jobCapacity = 10;
	
	int woodCost = 5;
	int concreteCost = 10;
	int steelCost = 5;

	int electricityUsage = 5;
	int waterUsage = 5;

	int income = 100;

	string type = "Commercial Shop";
	bool operational;//CS State
};

#endif
