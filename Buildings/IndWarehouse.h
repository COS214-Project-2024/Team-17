#ifndef INDWAREHOUSE_H
#define INDWAREHOUSE_H

#include "Industrial.h"

class IndWarehouse : public Industrial {
public:
    IndWarehouse();

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
    std::string type="Industrial Warehouse";
    bool operational;//CS State
};

#endif
