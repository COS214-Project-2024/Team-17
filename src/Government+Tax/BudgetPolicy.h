#ifndef BUDGETPOLICY_H
#define BUDGETPOLICY_H

#include "CityStructure.h"
/**
 * @class BudgetPolicy
 * @brief Abstract base class for budget policies in a city structure.
 *
 * This class provides an interface for applying budget policies.
 */
class BudgetPolicy
{
public:
    /**
     * @brief Applies the budget to a city structure.
     *
     * This function is meant to be implemented by derived classes to apply specific budget allocations.
     * @param city The CityStructure instance to which the budget is applied.
     * @param budget The budget amount to be allocated.
     */
  virtual void applyBudget(CityStructure &city, double budget) = 0;
      /**
     * @brief Virtual destructor for the BudgetPolicy class.
     */
  virtual ~BudgetPolicy() {}
};

#endif
