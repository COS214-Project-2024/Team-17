/**
 * @file BudgetPolicy.h
 * @brief Header file for the BudgetPolicy class, defining the base interface for city budget policies.
 * @details This file declares the BudgetPolicy class, an abstract base class for creating budget allocation
 * policies. Derived classes implement specific strategies for allocating a budget across different city
 * departments, allowing flexible policy implementations.
 * @see CityStructure for the class receiving the budget allocations.
 * @see Government for the entity that applies these policies in city management.
 * @note Derived policies include HealthPolicy, InfrastructureBudgetPolicy, and others for targeted budget strategies.
 * @author WORKONMYMACHINE TEAM
 */
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
