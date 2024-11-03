#ifndef RESHOUSE_H
#define RESHOUSE_H

#include "../../colours.h" // Testing colours and other includes
#include "Residential.h"

class ResHouse : public Residential
{
public:
    ResHouse();
    ~ResHouse();

    void displayBuildingInfo() override;

    int getCapacity() const override;
    void setCapacity(int capacity) override;

    // Observer
    void callUtilities(); // call Utilities in Buildings
    bool getState();
    void setState(bool state);

    std::string getBuildingType();

    bool moveIn(Citizen* resident);
    void moveOut(Citizen* resident);
    	
	int getElectricityUsage();
	int getWaterUsage();
	int getCurCitizenCount();
	
    void notifyEmployeeLeft(Citizen *employee);

    bool moveIn(Citizen *resident);
    void moveOut(Citizen *resident);

private:
    int capacity;
    string type = "Residential House";
    bool operational; // CS State

    vector<Citizen *> residents;
    // Resources
    int cost = 2500;

    int woodCost = 15;
    int steelCost = 10;
    int concreteCost = 20;

    int electricityUsage = 15;
    int waterUsage = 15;

    int popIncrease = 20;
};

#endif // RESHOUSE_H
