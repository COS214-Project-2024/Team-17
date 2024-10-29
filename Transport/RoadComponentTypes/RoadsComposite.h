#ifndef ROADSCOMPOSITE_H
#define ROADSCOMPOSITE_H

#include "../RoadComponent.h"
#include <vector>

class RoadsComposite : public RoadComponent
{
private:
	std::vector<RoadComponent *> components;

public:
	RoadsComposite(CityMediator *mediator);

	void displayInfo();

	void calculateTraffic();

	void add(RoadComponent *component);

	void remove(RoadComponent *component);

	float getDistance();

	void notifyChange(std::string message);

	~RoadsComposite() {}
};

#endif
