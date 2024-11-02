#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "CityStructure.h"
#include "BudgetPolicy.h"
#include <string>
#include <map>
#include <vector>

class CitezenTaxAB;
class Policy;

class Government
{
public:
  void processTaxes(CityStructure &city);
  void applyBudget(CityStructure &city);
  void setTaxRate(std::string category, double rate);
  void collectTaxes();
  void allocateTaxes(std::string department, double amount);
  void addCity(CityStructure &city);
  void setPolicy(Policy &policy);
  void setBudgetPolicy(BudgetPolicy &policy);

private:
  std::map<std::string, double> taxRates;
  std::map<std::string, double> cityTaxes;
  std::vector<CityStructure> cities;
  BudgetPolicy *budgetPolicy = nullptr;
};

#endif
