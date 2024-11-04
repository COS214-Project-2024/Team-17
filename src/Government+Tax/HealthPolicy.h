/**
 * @file HealthPolicy.h
 * @brief Header file for the HealthPolicy class, defining health-oriented budget allocation.
 * @details This file defines the HealthPolicy class, which implements a budget allocation strategy focused on health.
 * The policy allocates a significant portion of the budget to health, with remaining funds divided among education and infrastructure.
 * HealthPolicy integrates with the CityStructure to apply its unique budgeting approach in a health-prioritized manner.
 * @note HealthPolicy serves as one of several budget policies available to the Government class for city resource distribution.
 * @see BudgetPolicy for the base policy interface this class implements.
 * @see CityStructure for the structure it interacts with when applying budgets.
 * @see Government for the entity that applies this policy to a city’s budget.
 * @author WORKONMYMACHINE TEAM
 */
#ifndef HEALTHPOLICY_H
#define HEALTHPOLICY_H

#include "Policy.h"
#include "CityStructure.h"
/**
 * @class HealthPolicy
 * @brief Policy class for applying a budget specifically to health-related departments.
 */
class HealthPolicy : public Policy
{
public:
    /**
     * @brief Applies a budget allocation specifically for health departments in a city.
     * @param city The city structure receiving the health budget.
     * @param budget The amount to allocate to health.
     */
	void applyBudget(CityStructure &city, double budget);
};

#endif
