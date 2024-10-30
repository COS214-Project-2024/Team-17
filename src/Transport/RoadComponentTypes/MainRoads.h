#ifndef MAINROADS_H
#define MAINROADS_H

#include "../RoadComponent.h"

class MainRoads : public RoadComponent
{

public:
	MainRoads();

	void displayInfo();

	void calculateTraffic();

	float getDistance();

	void notifyChange(std::string message);

	~MainRoads() {}
};

#endif
