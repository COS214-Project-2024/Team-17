/**
 * @file InfrastructurePolicy.h
 * @brief Header file for the InfrastructurePolicy class, which handles budgets specifically for infrastructure needs.
 * @details This file contains the InfrastructurePolicy class, responsible for applying a budget focused on
 * infrastructure requirements. It inherits from the Policy interface to implement infrastructure-related
 * budget allocation within a city structure.
 * @see Policy for the base policy interface this class implements.
 * @see CityStructure for the structure this policy interacts with to apply budgets.
 * @note This class serves as a policy option for budget allocation, with a focus on infrastructure spending.
 * @author WORKONMYMACHINE TEAM
 */
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
