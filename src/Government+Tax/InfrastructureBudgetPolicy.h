#ifndef INFRASTRUCTUREBUDGETPOLICY_H
#define INFRASTRUCTUREBUDGETPOLICY_H

#include "BudgetPolicy.h"
#include "CityStructure.h"
/**
 * @class InfrastructureBudgetPolicy
 * @brief Budget policy for allocating funds specifically for infrastructure projects.
 */
class InfrastructureBudgetPolicy : public BudgetPolicy
{
public:
    /**
     * @brief Applies an infrastructure-specific budget to the city structure.
     * @param city The city structure receiving the infrastructure budget.
     * @param budget The amount to allocate to infrastructure.
     */
	void applyBudget(CityStructure &city, double budget);
};

#endif
