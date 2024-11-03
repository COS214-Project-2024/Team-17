#ifndef SERVHOSPITAL_H
#define SERVHOSPITAL_H

#include "Services.h"
class ServHospital :public Services {
public:
	ServHospital();
	~ServHospital();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;

    //Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);

	std::string getBuildingType();

	// Resources
	bool addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);
		
	int getElectricityUsage();
	int getWaterUsage();
	int getCurCitizenCount();
	

private:
	int visitors;
    bool operational; // CS State
    string type = "Service Hospital";

	// Resources
	vector<Citizen*> employees;
	int cost = 1500;

    int woodCost = 5;
    int steelCost = 10;
    int concreteCost = 15;

    int electricityUsage = 10;
    int waterUsage = 10;

    int happinessIncrease = 5;
	int jobCapacity = 20;
	int cityIncome = 50;
};

#endif
