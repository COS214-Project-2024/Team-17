#ifndef LANDCCENTER_H
#define LANDCCENTER_H

#include "Landmark.h"

class LandCCenter : public Landmark {
public:
    LandCCenter();

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
