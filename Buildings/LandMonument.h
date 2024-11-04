#ifndef LANDMONUMENT_H
#define LANDMONUMENT_H

#include "Landmark.h"

class LandMonument : public Landmark {
public:
    LandMonument();

    void displayBuildingInfo() override;

	int getVisitors() override;
	void setVisitors(int visitors) override;

	// bool checkBuildRequirements() override;
	// void createBuilding() override;
	// void affectEmotionalState() override;

private:
	int visitors;
};

#endif
