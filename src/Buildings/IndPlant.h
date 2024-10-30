#ifndef INDPLANT_H
#define INDPLANT_H

#include "Industrial.h"

class IndPlant : public Industrial {
public:
    IndPlant();

    void displayBuildingInfo() override;

    int getProductionCapacity() override;
	void setProductionCapacity(int capacity) override;

    //Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	string getBuildingType();

	// virtual bool checkBuildRequirements() override;
	// virtual void increaseJobs() override;
	// virtual void affectEmotionalState() override;

	void addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);

private:
	vector<Citizen*> employees;

	//Resources

	int cost = 1500;

    int jobCapacity = 10;
	
	int woodCost = 20;
	int steelCost = 10;
	int concreteCost = 10;

	int electricityUsage = 10;
	int waterUsage = 5;

	int steelProduction = 10;

    string type="Industrial Plant";
    bool operational;//CS State
};

#endif
