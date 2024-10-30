#ifndef BUILDING_H
#define BUILDING_H

#include "../../colours.h" // Testing colours and other includes
#include "../Utilities/UtilityManager.h"
// #include "../Utilities/CityMediator.h"

class UtilityManager;

class Building
{
public:
    Building();

    virtual void displayBuildingInfo() = 0;
    virtual ~Building() = default;

    // Building(CityMediator* mediator, string type);
    virtual bool getState() = 0;
    virtual string getBuildingType();

    virtual bool checkBuildRequirements() = 0;

private:
    vector<UtilityManager *> utilities;
    string name;
    // CityMediator* mediator;
    bool operational; // state
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
