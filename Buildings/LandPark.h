#ifndef LANDPARK_H
#define LANDPARK_H

#include "Landmark.h"

class LandPark : public Landmark {
public:
    LandPark();

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
