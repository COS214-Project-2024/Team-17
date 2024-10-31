#ifndef ROADCOMPONENT_H
#define ROADCOMPONENT_H

class CityMediator;
// #include "../Citizens/CityMediator.h"
#include "../Citizens/CityBlock.h"
#include <vector>
#include <cstdint>
class RoadState;
class RoadIterator;

class RoadComponent : CityBlock
{

private:
	RoadState *state;

protected:
	float distance;
	int startX, startY, endX, endY;
	std::vector<RoadComponent *> connections;

public:
	virtual void displayInfo() = 0;

	virtual void calculateTraffic() = 0;

	virtual float getDistance() = 0;

	RoadIterator *createIterator();

	void setState(RoadState *newState);

	void handleTraffic();

	RoadComponent(int startX, int startY, int endX, int endY);

	virtual void notifyChange();

	virtual void accept(TaxAndBudgetVisitor *visitor);

	virtual ~RoadComponent();

	virtual void addConnection(RoadComponent *connection, float distance) = 0;

	virtual std::vector<RoadComponent *> getConnections();

	// virtual void removeConnection(RoadComponent *connection) = 0;

	virtual float calculateDistance(int x, int y) = 0;
};

#endif
