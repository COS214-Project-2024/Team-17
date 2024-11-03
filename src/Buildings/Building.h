#ifndef BUILDING_H
#define BUILDING_H

#include "../../colours.h" // Testing colours and other includes
#include "../Utilities/UtilityManager.h"
#include "../Citizens/CityMediator.h"
#include "../Citizens/CityBlock.h"

#include "../Citizens/Citizen.h"

#include "../resources.h"
#include "BuildingRequirements.h"

class CityMediator;
class UtilityManager;

class Building : public CityBlock
{
public:
    Building(string type = "");

    virtual void displayBuildingInfo() = 0;
    virtual ~Building() = default;

    virtual bool getState() = 0;
    virtual string getBuildingType();

    virtual bool checkBuildRequirements() = 0;

    void notifyChange(std::string message);
    // void accept(TaxAndBudgetVisitor *visitor);

    int getXCoordinate();
    int getYCoordinate();

    void setXCoordinate(int x);
    void setYCoordinate(int y);

    virtual bool addEmployee(Citizen *employee) = 0;
    virtual void removeEmployee(Citizen *employee) = 0;
    virtual void notifyEmployeeLeft(Citizen *employee) = 0;
    virtual bool hasJob() = 0;

    virtual bool moveIn(Citizen *resident) = 0;
    virtual void moveOut(Citizen *resident) = 0;

    virtual int getElectricityUsage() = 0;
    virtual int getWaterUsage() = 0;
    virtual int getCurCitizenCount() = 0;

private:
    vector<UtilityManager *> utilities;
    string name;
    CityMediator *mediator;
    bool operational; // state

    // Coordinates:
    int xCoordinate;
    int yCoordinate;
};

#endif // BUILDING_H

////// EVERYTHING BELOW IS FROM VP - IT IS SUBJECT TO CHANGE //////

// #ifndef BUILDING_H
// #define BUILDING_H

// class Building : UtilityObserver, CityBlock {

// private:
// 	string name;
// 	CityMediator* mediator;

// 	virtual bool checkBuildRequirements() = 0;

// public:
// 	virtual void createBuilding() = 0;

// 	void update(string& utilityStatus);

// 	void receiveElectricity();

// 	void receiveWater();

// 	void removeWaste();

// 	void removeSewage();

// 	void notifyOutage(string& utility);

// 	void notifyNoWater(string& utility);

// 	void notifyWasteRemove(string& utility);

// 	void notifySewageRemove(string& utility);

// 	virtual void affectEmotionalState() = 0;

// 	Building(CityMediator* mediator, string type);

// 	string getType();

// 	void construct();

// 	void abstract_notifyChange();

// 	void accept(TaxAndBudgetVisitor* visitor);
// };

// #endif
