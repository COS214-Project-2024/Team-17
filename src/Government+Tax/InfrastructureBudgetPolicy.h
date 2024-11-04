/**
 * @file InfrastructureBudgetPolicy.h
 * @brief Header file for the InfrastructureBudgetPolicy class, which allocates funds for infrastructure projects.
 * @details This file defines the InfrastructureBudgetPolicy class, a budget policy focused on allocating
 * funds specifically for infrastructure development within a city structure. It implements the BudgetPolicy
 * interface to apply infrastructure-centered budgets to city departments.
 * @see BudgetPolicy for the base policy interface this class implements.
 * @see CityStructure for the structure this policy interacts with to apply budgets.
 * @note This class is used in conjunction with the Government class to enforce infrastructure-based budget allocation.
 * @author WORKONMYMACHINE TEAM
 */
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
