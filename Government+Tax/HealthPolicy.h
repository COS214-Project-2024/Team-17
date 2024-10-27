#ifndef HEALTHPOLICY_H
#define HEALTHPOLICY_H

#include "Policy.h"
#include "CityStructure.h"


class HealthPolicy : public Policy {
public:
  	void applyBudget(CityStructure& city, double budget);
};

#endif
