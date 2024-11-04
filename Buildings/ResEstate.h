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

private:
    int capacity;
};

#endif // RESESTATE_H
