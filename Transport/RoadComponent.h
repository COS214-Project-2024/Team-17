#ifndef ROADCOMPONENT_H
#define ROADCOMPONENT_H

class RoadComponent : CityBlock {

private:
	RoadState* state;
	TrafficStatus status;

public:
	virtual void displayInfo() = 0;

	virtual void calculateTraffic() = 0;

	virtual float getDistance() = 0;

	RoadIterator createIterator();

	void setState(RoadState* newState);

	void handleTraffic();

	RoadComponent(CityMediator* mediator);

	void updateTraffic(TrafficStatus newStatus);

	void notifyChange();
};

#endif
