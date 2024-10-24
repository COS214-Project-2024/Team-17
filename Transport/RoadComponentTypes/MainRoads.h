#ifndef MAINROADS_H
#define MAINROADS_H

#include "../RoadComponent.h"

class MainRoads : public RoadComponent
{

public:
	MainRoads(CityMediator *mediator);

	void displayInfo();

	void calculateTraffic();

	float getDistance();
};

#endif
