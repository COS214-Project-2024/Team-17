#include "Government.h"
#include "CitizenTaxAB.h"
#include <iostream>

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

void Government::setBudgetPolicy(BudgetPolicy &policy)
{
  this->budgetPolicy = &policy;
}

void Government::addPolicy(Policy &policy, std::string name)
{
  this->laws[name] = &policy;
}

void Government::removePolicy(std::string name)
{
  auto it = this->laws.find(name);
  if (it != this->laws.end()) 
  {
    delete it->second;
    it->second = nullptr;
  }
}

void Government::enactPolicies()
{
  for(auto policy : laws)
  {
    if(policy.second)
    {
      policy.second->enact();
    }
  }
}

void Government::listPolicies()
{
  for(auto policy : laws)
  {
    std::cout << "- " << policy.first << std::endl;
  }
}

void Government::setTaxRate(std::string category, double rate)
{
  taxRates[category] = rate;
}

void Government::collectTaxes()
{
  for (CityStructure &citystructure : cities)
  {
    processTaxes(citystructure);
  }
}

void Government::addCity(CityStructure &city)
{
  this->cities.push_back(city);
}

void Government::allocateTaxes(std::string department, double amount)
{
  this->taxRates[department] = amount;
}