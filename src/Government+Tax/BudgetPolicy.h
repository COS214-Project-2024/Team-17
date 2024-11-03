#ifndef BUDGETPOLICY_H
#define BUDGETPOLICY_H

#include "CityStructure.h"

class BudgetPolicy
{
public:
  virtual void applyBudget(CityStructure &city, double budget) = 0;
  virtual ~BudgetPolicy() {}
};

#endif
