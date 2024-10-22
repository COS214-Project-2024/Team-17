#ifndef ROADITERATOR_H
#define ROADITERATOR_H

class RoadIterator {


public:
	virtual void first() = 0;

	virtual void next() = 0;

	virtual void isDone() = 0;

	virtual void currentRoad() = 0;
};

#endif
