#include "InfrastructurePolicy.h"

void InfrastructurePolicy::applyBudget(CityStructure& city, double income) {
  double taxes = income;
  double budgetHealth = taxes * 0.3;
  double budgetEducation = taxes * 0.2;
  double budgetInfrastucture = taxes * 0.5;

  city.allocateBudget("Health" , budgetHealth);
  city.allocateBudget("Education" , budgetEducation);
  city.allocateBudget("Infrastructure" , budgetInfrastucture);
}
