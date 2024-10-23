#ifndef BUILDING_H
#define BUILDING_H

class Building : UtilityObserver, CityBlock {

private:
	string name;
	CityMediator* mediator;

	virtual bool checkBuildRequirements() = 0;

public:
	virtual void createBuilding() = 0;

	void update(string& utilityStatus);

	void receiveElectricity();

	void receiveWater();

	void removeWaste();

	void removeSewage();

	void notifyOutage(string& utility);

	void notifyNoWater(string& utility);

	void notifyWasteRemove(string& utility);

	void notifySewageRemove(string& utility);

	virtual void affectEmotionalState() = 0;

	Building(CityMediator* mediator, string type);

	string getType();

	void construct();

	void abstract_notifyChange();

	void accept(TaxAndBudgetVisitor* visitor);
};

#endif
