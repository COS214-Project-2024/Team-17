#ifndef RESFLAT_H
#define RESFLAT_H

#include "Residential.h"

class ResFlat : public Residential {
public:
    ResFlat();

    void displayBuildingInfo() override;

    int getCapacity() const override;
    void setCapacity(int capacity) override;

    // virtual bool checkBuildRequirements() override;
	// virtual int increasePopulation() override;
	// virtual void affectEmotionalState() override;

//Observer
	void callUtilities()override;//call Utilities in Buildings
	bool getState()override;
	void setState(bool state)override;
	// int getTotalCapacity();
	// int getCurrentStorage();
	// int setCurrentStorage(int storage);
	std::string getBuildingType()override;

private:
    int capacity;
    std::string type="Residential Flat";
    bool operational;//CS State
};

#endif // RESFLAT_H
