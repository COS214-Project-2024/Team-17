#include "InfrastructurePolicy.h"

void InfrastructurePolicy::applyBudget(CityStructure& city, double budget) {
  double budgetHealth = budget * 0.3;
  double budgetEducation = budget * 0.2;
  double budgetInfrastucture = budget * 0.5;

  city.allocateBudget("Health" , budgetHealth);
  city.allocateBudget("Education" , budgetEducation);
  city.allocateBudget("Infrastructure" , budgetInfrastucture);
}
