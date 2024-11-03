#ifndef INFRASTRUCTUREBUDGETPOLICY_H
#define INFRASTRUCTUREBUDGETPOLICY_H

#include "BudgetPolicy.h"
#include "CityStructure.h"

class InfrastructureBudgetPolicy : public BudgetPolicy
{
public:
	void applyBudget(CityStructure &city, double budget);
};

#endif
