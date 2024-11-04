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

private:
    int productionCapacity;
};

#endif
