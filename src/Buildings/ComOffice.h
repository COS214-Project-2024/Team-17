#ifndef COMOFFICE_H
#define COMOFFICE_H

#include "Commercial.h"

class ComOffice : public Commercial {
public:
    ComOffice();

    void displayBuildingInfo() override;

	int getJobCapacity() override;
	void setJobCapacity(int capacity) override;

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	string getBuildingType()override;

	// virtual bool checkBuildRequirements() = 0;
	// virtual int increasePopulation() = 0;
	// virtual void affectEmotionalState() = 0;
	// virtual bool checkBuildRequirements() = 0;
	// virtual void increaseJobs() = 0;
	// virtual void affectEmotionalState() = 0;

private:
    vector<Citizen*> employees;

    int jobCapacity = 100;
	
	int woodCost = 20;
	int steelCost = 25;
	int concreteCost = 25;

	int electricityUsage = 20;
	int waterUsage = 10;

	int income = 500;
	
	string type = "Commercial Office";
	bool operational;//CS State
};

#endif
