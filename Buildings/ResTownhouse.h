#ifndef RESTOWNHOUSE_H
#define RESTOWNHOUSE_H

#include "Residential.h"

class ResTownhouse : public Residential {
public:
    ResTownhouse();

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
    string type="Residential Townhouse";
    bool operational;//CS State
};

#endif // RESTOWNHOUSE_H
