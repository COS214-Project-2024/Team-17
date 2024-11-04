#ifndef INDFACTORY_H
#define INDFACTORY_H

#include "Industrial.h"

class IndFactory : public Industrial {
public:
    IndFactory();

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
