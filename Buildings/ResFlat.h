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

private:
    int capacity;
};

#endif // RESFLAT_H
