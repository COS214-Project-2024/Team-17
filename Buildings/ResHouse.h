#ifndef RESHOUSE_H
#define RESHOUSE_H

#include "../colours.h" // Testing colours and other includes
#include "Residential.h"

class ResHouse : public Residential {
public:
    ResHouse();

    void displayBuildingInfo() override;

    int getCapacity() const override;
    void setCapacity(int capacity) override;

    //Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType();

    // virtual bool checkBuildRequirements() override;
	// virtual int increasePopulation() override;
	// virtual void affectEmotionalState() override;

private:
    int capacity;
    string type="Residential House";
    bool operational;//CS State
};

#endif // RESHOUSE_H
