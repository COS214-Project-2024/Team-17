#ifndef POLICY_H
#define POLICY_H

#include "Government.h"

class Policy {
public:
	virtual void applyBudget(CityStructure& city, double taxes) = 0;
};

#endif
