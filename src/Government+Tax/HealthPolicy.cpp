#include "HealthPolicy.h"
#include <iostream>

/**
 * @brief Apply a health-focused budget allocation to a city.
 * 
 * Allocates 50% of the budget to health, 20% to education, and 30% to infrastructure.
 * 
 * @param city The city to apply the budget to.
 * @param budget The total budget to distribute.
 */
void HealthPolicy::applyBudget(CityStructure &city, double budget)
{
  double budgetHealth = budget * 0.5;
  double budgetEducation = budget * 0.2;
  double budgetInfrastucture = budget * 0.3;

  city.allocateBudget("Health", budgetHealth);
  city.allocateBudget("Education", budgetEducation);
  city.allocateBudget("Infrastructure", budgetInfrastucture);

  std::cout << "Allocated Budget to Health\n";
}
