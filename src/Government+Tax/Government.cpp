#include "Government.h"
#include "CitizenTaxAB.h"
#include <iostream>
/**
 * @brief Processes taxes for a specified city.
 * 
 * @param city The city to process taxes for.
 */
void Government::processTaxes(CityStructure &city)
{
  city.accept(new CitizenTaxAB());
  double income = city.getIncome();
  double totalTax = 0;

  for (const auto &[category, rate] : taxRates)
  {
    double taxforCategory = income * rate;
    totalTax += taxforCategory;
  }

  cityTaxes[city.getName()] += totalTax;
}
/**
 * @brief Applies the budget policy to a city or allocates default budgets.
 * 
 * @param city The city to apply the budget to.
 */
void Government::applyBudget(CityStructure &city)
{
  if (budgetPolicy)
  {
    this->budgetPolicy->applyBudget(city, cityTaxes[city.getName()]);
  }
  else
  {
    double budget = cityTaxes[city.getName()];
    double budgetHealth = budget * 0.33;
    double budgetEducation = budget * 0.33;
    double budgetInfrastucture = budget * 0.33;

    city.allocateBudget("Health", budgetHealth);
    city.allocateBudget("Education", budgetEducation);
    city.allocateBudget("Infrastructure", budgetInfrastucture);
  }
}
/**
 * @brief Sets the budget policy for the government.
 * 
 * @param policy Reference to the new budget policy.
 */
void Government::setBudgetPolicy(BudgetPolicy &policy)
{
  this->budgetPolicy = &policy;
}
/**
 * @brief Sets the tax rate for a specific category.
 * 
 * @param category Name of the tax category.
 * @param rate Tax rate to set for the category.
 */
void Government::setTaxRate(std::string category, double rate)
{
  taxRates[category] = rate;
}
/**
 * @brief Collects taxes for all cities managed by the government.
 */
void Government::collectTaxes()
{
  for (CityStructure &citystructure : cities)
  {
    processTaxes(citystructure);
  }
}
/**
 * @brief Adds a city to the government’s jurisdiction.
 * 
 * @param city Reference to the CityStructure to add.
 */
void Government::addCity(CityStructure &city)
{
  this->cities.push_back(city);
}
/**
 * @brief Allocates a specified tax amount to a department.
 * 
 * @param department The department to allocate taxes to.
 * @param amount The amount of taxes to allocate.
 */
void Government::allocateTaxes(std::string department, double amount)
{
  this->taxRates[department] = amount;
}