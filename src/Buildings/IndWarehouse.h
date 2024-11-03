#ifndef INDWAREHOUSE_H
#define INDWAREHOUSE_H

#include "Industrial.h"

class IndWarehouse : public Industrial {
public:
    IndWarehouse();
	~IndWarehouse();

    void displayBuildingInfo() override;

    int getProductionCapacity() override;
	void setProductionCapacity(int capacity) override;

    //Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);

	std::string getBuildingType();

	bool addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);
	void notifyEmployeeLeft(Citizen* employee);
	bool hasJob();

private:
    vector<Citizen*> employees;

	//Resources

	int cost = 1500;

    int jobCapacity = 10;
	
	int woodCost = 10;
	int concreteCost = 20;
	int steelCost = 10;

	int electricityUsage = 10;
	int waterUsage = 5;

	int concreteProduction = 5;

    string type = "Industrial Warehouse";
    bool operational;//CS State
};

#endif
