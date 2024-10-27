#ifndef INFRASTRUCTUREPOLICY_H
#define INFRASTRUCTUREPOLICY_H

#include "Policy.h"
#include "CityStructure.h"

class InfrastructurePolicy : public Policy {
public:
  	void applyBudget(CityStructure& city, double budget);
};

#endif
