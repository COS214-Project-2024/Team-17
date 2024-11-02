#ifndef SERVEDUCATION_H
#define SERVEDUCATION_H

#include "Services.h"

class ServEducation : public Services {
public:
	ServEducation();
	~ServEducation();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;

	//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);

	string getBuildingType();

	// Resources
	bool addEmployee(Citizen* employee);
	void removeEmployee(Citizen* employee);
	bool hasJob();

private:
	int visitors;
	string type="Service Education";
	bool operational;//CS State

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
