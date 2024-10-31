#ifndef HIGHWAYS_H
#define HIGHWAYS_H

#include "../RoadComponent.h"

class Highways : public RoadComponent
{

public:
	Highways(int sX, int sY, int eX, int eY);

	void displayInfo();

	void calculateTraffic();

	float getDistance();

	void notifyChange(std::string message);

	void addConnection(RoadComponent *connection, float distance);

	float calculateDistance(int x, int y);

	~Highways() {}
};

#endif
