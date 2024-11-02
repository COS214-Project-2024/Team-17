#ifndef COMOFFICE_H
#define COMOFFICE_H

#include "Commercial.h"

class ComOffice : public Commercial {
public:
    ComOffice();
	~ComOffice();

    void displayBuildingInfo() override;

	int getJobCapacity() override;
	void setJobCapacity(int capacity) override;

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);

	string getBuildingType()override;

	bool addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);

private:
    vector<Citizen*> employees;

	//Recources
	int cost = 1500;

    int jobCapacity = 20;
	
	int woodCost = 5;
	int concreteCost = 10;
	int steelCost = 5;

	int electricityUsage = 10;
	int waterUsage = 10;

	int income = 200;

	string type = "Commercial Office";
	bool operational;//CS State
};

#endif
