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
