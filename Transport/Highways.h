#ifndef HIGHWAYS_H
#define HIGHWAYS_H

class Highways : RoadComponent {

public:
	float distance;

	void displayInfo();

	void calculateTraffic();

	float getDistance();
};

#endif
