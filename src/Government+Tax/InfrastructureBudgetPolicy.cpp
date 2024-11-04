#include "InfrastructureBudgetPolicy.h"
/**
 * @brief Apply a budget to the city's health, education, and infrastructure departments.
 * 
 * This policy allocates 30% of the budget to health, 20% to education, and 50% to infrastructure.
 * 
 * @param city The CityStructure to which the budget will be applied.
 * @param budget The total budget amount.
 */
void InfrastructureBudgetPolicy::applyBudget(CityStructure &city, double budget)
{
  double budgetHealth = budget * 0.3;
  double budgetEducation = budget * 0.2;
  double budgetInfrastucture = budget * 0.5;

  city.allocateBudget("Health", budgetHealth);
  city.allocateBudget("Education", budgetEducation);
  city.allocateBudget("Infrastructure", budgetInfrastucture);

}
