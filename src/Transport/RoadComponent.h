#ifndef ROADCOMPONENT_H
#define ROADCOMPONENT_H

class CityMediator;
// #include "../Citizens/CityMediator.h"
#include "../Citizens/CityBlock.h"
class RoadState;
class RoadIterator;

class RoadComponent : CityBlock
{

private:
	RoadState *state;

protected:
	float distance;

public:
	virtual void displayInfo() = 0;

	virtual void calculateTraffic() = 0;

	virtual float getDistance() = 0;

	RoadIterator *createIterator();

	void setState(RoadState *newState);

	void handleTraffic();

	RoadComponent(CityMediator *mediator);

	virtual void notifyChange();

	virtual void accept(TaxAndBudgetVisitor *visitor);

	virtual ~RoadComponent();
};

#endif
