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

private:
    int capacity;
};

#endif // RESHOUSE_H
