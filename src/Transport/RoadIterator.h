#ifndef ROADITERATOR_H
#define ROADITERATOR_H

class RoadComponent;

class RoadIterator
{

public:
	virtual void first() = 0;

	virtual void next() = 0;

	virtual bool isDone() = 0;

	virtual RoadComponent *currentRoad() = 0;
};

#endif
