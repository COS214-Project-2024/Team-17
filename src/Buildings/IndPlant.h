#ifndef INDPLANT_H
#define INDPLANT_H

#include "Industrial.h"

class IndPlant : public Industrial {
public:
    IndPlant();
	~IndPlant();

    void displayBuildingInfo() override;

    int getProductionCapacity() override;
	void setProductionCapacity(int capacity) override;

    //Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);

	string getBuildingType();

	bool addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);

private:
	vector<Citizen*> employees;

	//Resources

	int cost = 1500;

    int jobCapacity = 10;
	
	int woodCost = 10;
	int concreteCost = 10;
	int steelCost = 20;
	

	int electricityUsage = 10;
	int waterUsage = 5;

	int steelProduction = 5;

    string type="Industrial Plant";
    bool operational;//CS State
};

#endif
