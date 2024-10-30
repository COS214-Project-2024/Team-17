#ifndef HIGHWAYS_H
#define HIGHWAYS_H

#include "../RoadComponent.h"

class Highways : public RoadComponent
{

public:
	Highways(CityMediator *mediator);

	void displayInfo();

	void calculateTraffic();

	float getDistance();

	void notifyChange(std::string message);

	~Highways() {}
};

#endif
