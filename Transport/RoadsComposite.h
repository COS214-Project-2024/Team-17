#ifndef ROADSCOMPOSITE_H
#define ROADSCOMPOSITE_H

class RoadsComposite : RoadComponent {

public:
	vector<shared_ptr<RoadComponent>> components;

	void displayInfo();

	void calculateTraffic();

	void add(RoadComponent* component);

	void remove(RoadComponent* component);

	float getDistance();
};

#endif
