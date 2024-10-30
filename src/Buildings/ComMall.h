#ifndef COMMALL_H
#define COMMALL_H

#include "Commercial.h"

class ComMall : public Commercial {
public:
    ComMall();

    void displayBuildingInfo() override;

	virtual int getJobCapacity() override;
	virtual void setJobCapacity(int capacity) override;

	// Observer
	void callUtilities(); //call Utilities in Buildings
	bool getState();
	void setState(bool state);
	
	string getBuildingType();

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

	void addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);

private:
	vector<Citizen*> employees;

	//Resources

	int cost = 5000;

    int jobCapacity = 100;
	
	int woodCost = 20;
	int concreteCost = 25;
	int steelCost = 25;

	int electricityUsage = 20;
	int waterUsage = 20;

	int income = 500;

	string type = "Commercial Mall";
	bool operational; //CS State
};

#endif