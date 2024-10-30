#ifndef COMMALL_H
#define COMMALL_H

#include "Commercial.h"

#include "../resources.h"

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
	void addEmployee(Citizen* employee);
	string getBuildingType();

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
	vector<Citizen*> employees;
    int jobCapacity;
	int woodCost = 100;
	int steelCost = 100;
	int concreteCost = 100;
	string type = "Commercial Mall";
	bool operational; //CS State
};

#endif