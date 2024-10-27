#ifndef POLICY_H
#define POLICY_H

#include "CityStructure.h"

class Policy {
public:
	virtual void applyBudget(CityStructure& city, double budget) = 0;
  virtual ~Policy() {}
};

#endif
