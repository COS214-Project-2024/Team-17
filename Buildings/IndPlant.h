#ifndef INDPLANT_H
#define INDPLANT_H

#include "Industrial.h"

class IndPlant : public Industrial {
public:
    IndPlant();

    void displayBuildingInfo() override;

    int getProductionCapacity() override;
	void setProductionCapacity(int capacity) override;

	// virtual bool checkBuildRequirements() override;
	// virtual void increaseJobs() override;
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
    int productionCapacity;
    std::string type="Industrial Plant";
    bool operational;//CS State
};

#endif
