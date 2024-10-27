#include "HealthPolicy.h"

void HealthPolicy::applyBudget(CityStructure& city, double income) {
  double taxes = income;
  double budgetHealth = taxes * 0.5;
  double budgetEducation = taxes * 0.2;
  double budgetInfrastucture = taxes * 0.3;

  city.allocateBudget("Health" , budgetHealth);
  city.allocateBudget("Education" , budgetEducation);
  city.allocateBudget("Infrastructure" , budgetInfrastucture);
}
