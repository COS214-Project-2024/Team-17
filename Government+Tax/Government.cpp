#include "Government.h"
#include <iostream>

void Government::processTaxes(CityStructure &city)
{
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
  if (policy)
  {
    this->policy->applyBudget(city, cityTaxes[city.getName()]);
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

void Government::setPolicy(Policy &policy)
{
  std::cout << "setting government policy\n";
  this->policy = &policy;
}

void Government::setTaxRate(std::string category, double rate)
{
  std::cout << "setting tax rate\n";
  taxRates[category] = rate;
}

void Government::collectTaxes()
{
  std::cout << "collecting taxes for all citystructures\n";
  for (CityStructure &citystructure : cities)
  {
    processTaxes(citystructure);
  }
}

void Government::addCity(CityStructure &city)
{
  std::cout << "added city\n";
  this->cities.push_back(city);
}

void Government::allocateTaxes(std::string department, double amount)
{
  std::cout << "allocated taxes to department\n";
  this->taxRates[department] = amount;
}

TaxHandler *Government::createTaxHandlerChain()
{
  std::cout << "creating tax handler\n";
  TaxRateHandler *rateHandler = new TaxRateHandler();
  TaxCollectionHandler *collectionHanlder = new TaxCollectionHandler();
  TaxAllocationHandler *allocationHandler = new TaxAllocationHandler();

  rateHandler->setNext(collectionHanlder);
  collectionHanlder->setNext(allocationHandler);
  return rateHandler;
}
