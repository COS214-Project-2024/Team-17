#include "HealthPolicy.h"
#include <iostream>

void HealthPolicy::applyBudget(CityStructure& city, double budget) {
  double budgetHealth = budget * 0.5;
  double budgetEducation = budget * 0.2;
  double budgetInfrastucture = budget * 0.3;

  city.allocateBudget("Health" , budgetHealth);
  city.allocateBudget("Education" , budgetEducation);
  city.allocateBudget("Infrastructure" , budgetInfrastucture);

  std::cout << "Allocated Healh\n";
}
