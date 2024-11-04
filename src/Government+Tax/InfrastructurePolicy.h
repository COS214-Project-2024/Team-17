#ifndef INFRASTRUCTUREPOLICY_H
#define INFRASTRUCTUREPOLICY_H

#include "Policy.h"
#include "CityStructure.h"
/**
 * @class InfrastructurePolicy
 * @brief Policy class for handling budgets related to infrastructure.
 */
class InfrastructurePolicy : public Policy
{
public:
    /**
     * @brief Applies an infrastructure-related budget to a city structure.
     * @param city The city structure receiving the budget.
     * @param budget The budget amount to allocate to infrastructure.
     */
	void applyBudget(CityStructure &city, double budget);
};

#endif
