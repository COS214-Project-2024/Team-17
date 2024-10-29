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

    // virtual bool checkBuildRequirements() override;
	// virtual int increasePopulation() override;
	// virtual void affectEmotionalState() override;

//Observer
	void callUtilities();//call Utilities in Buildings
	bool getState();
	void setState(bool state);
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType()override;

private:
    int capacity;
    std::string type="Residential House";
    bool operational;//CS State
};

#endif // RESHOUSE_H
