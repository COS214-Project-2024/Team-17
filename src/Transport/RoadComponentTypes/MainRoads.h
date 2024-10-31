#ifndef MAINROADS_H
#define MAINROADS_H

#include "../RoadComponent.h"

class MainRoads : public RoadComponent
{

public:
	MainRoads(int sX, int sY, int eX, int eY);

	void displayInfo();

	void calculateTraffic();

	float getDistance();

	void notifyChange(std::string message);

	void addConnection(RoadComponent *connection, float distance);

	float calculateDistance(int x, int y);

	~MainRoads() {}
};

#endif
