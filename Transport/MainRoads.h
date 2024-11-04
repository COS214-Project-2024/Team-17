#ifndef MAINROADS_H
#define MAINROADS_H

class MainRoads : RoadComponent {

public:
	float distance;

	void displayInfo();

	void calculateTraffic();

	float getDistance();
};

#endif
