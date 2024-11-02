#ifndef COMMALL_H
#define COMMALL_H

#include "Commercial.h"

class ComMall : public Commercial {
public:
    ComMall();
	~ComMall();

    void displayBuildingInfo() override;

	virtual int getJobCapacity() override;
	virtual void setJobCapacity(int capacity) override;

	// Observer
	void callUtilities(); //call Utilities in Buildings
	bool getState();
	void setState(bool state);
	
	string getBuildingType();

	bool addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);
	bool hasJob();

private:
	vector<Citizen*> employees;

	//Resources

	int cost = BuildingRequirements::mallBuildCost;

    int jobCapacity = 100;
	
	int woodCost = BuildingRequirements::mallWoodCost;
	int concreteCost = BuildingRequirements::mallConcreteCost;
	int steelCost = BuildingRequirements::mallSteelCost;

	int electricityUsage = 20;
	int waterUsage = 20;

	int income = 500;

	string type = "Commercial Mall";
	bool operational; //CS State
};

#endif