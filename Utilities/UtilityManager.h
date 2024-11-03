#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H

class UtilityManager : CityBlock {

private:
	UtilPowerPlants powerPlant;
	UtilWaterSupply waterSupply;
	UtilWasteMan wasteManagement;
	UtilSewageSyst sewageSystem;
	CityMediator* mediator;

public:
	UtilityManager();

	void supplyElectricity(Building& building);

	void provideWater(Building& building);

	void manageWaste(Building& building);

	void manageSewage(Building& building);

	void updateUtilities(Building& building);

	virtual void addObserver(Building* observer) = 0;

	virtual void removeObserver(Building* observer) = 0;

	virtual void notifyObservers() = 0;

	void Utilities(CityMediator* mediator);

	void abstract_notifyChange();
};

#endif
