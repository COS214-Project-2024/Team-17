#ifndef SERVHOSPITAL_H
#define SERVHOSPITAL_H

#include "Services.h"
class ServHospital :public Services {
public:
	ServHospital();

	void displayBuildingInfo() override;	

	int getVisitors() override;
	void setVisitors(int visitors) override;

    //Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType();

private:
	int visitors;
    bool operational; // CS State
    string type = "Service Hospital";

	// Resources
	int cost = 1500;

    int woodCost = 5;
    int steelCost = 10;
    int concreteCost = 15;

    int electricityUsage = 10;
    int waterUsage = 10;

    int happinessIncrease = 5;
	int jobCapacity = 20;
	int cityIncome = 50;

	/*
Education	Security	Entertainment
Wood:					5	5	10
Concrete:				15	15	15
Steel:					10	10	10
				
Electricity Usage:		5	5	15
Water Usage				10	15	15
				
Cost:					1500	1500	2000

Happiness increase		5	5	10
Jobs:					20	10	10
City Income				50	50	100		
*/
};

#endif
