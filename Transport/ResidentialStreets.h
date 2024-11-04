#ifndef RESIDENTIALSTREETS_H
#define RESIDENTIALSTREETS_H

class ResidentialStreets : RoadComponent {

public:
	float distance;

	void displayInfo();

	void calculateTraffic();

	float getDistance();
};

#endif
