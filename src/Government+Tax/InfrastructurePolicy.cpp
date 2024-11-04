#include "InfrastructurePolicy.h"
#include <iostream>
/**
 * @brief Apply a Infrastructure-focused budget allocation to a city.
 * 
 * Allocates 30% of the budget to health, 20% to education, and 50% to infrastructure.
 * 
 * @param city The city to apply the budget to.
 * @param budget The total budget to distribute.
 */
void InfrastructurePolicy::applyBudget(CityStructure &city, double budget)
{
  double budgetHealth = budget * 0.3;
  double budgetEducation = budget * 0.2;
  double budgetInfrastucture = budget * 0.5;

  city.allocateBudget("Health", budgetHealth);
  city.allocateBudget("Education", budgetEducation);
  city.allocateBudget("Infrastructure", budgetInfrastucture);

  std::cout << "Allocated Budget to Infrastructure\n";
}
