#ifndef RESESTATE_H
#define RESESTATE_H

#include "Residential.h"

class ResEstate : public Residential {
public:
    ResEstate();

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
    std::string type="Residential Estate";
    bool operational;//CS State
};

#endif // RESESTATE_H
