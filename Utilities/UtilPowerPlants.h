#ifndef UTILPOWERPLANTS_H
#define UTILPOWERPLANTS_H

class UtilPowerPlants {

private:
	bool operational;

public:
	UtilPowerPlants();

	bool isOperational();

	void shutDown();

	void restart();

	void generateElectricity(Building& building);

	void addObserver(Building* observer);

	void removeObserver(Building* observer);

	void notifyObservers();
};

#endif
