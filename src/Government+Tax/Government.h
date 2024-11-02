#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "CityStructure.h"
#include "BudgetPolicy.h"
#include "Policy.h"
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
  void addPolicy(Policy &policy , std::string name);
  void removePolicy(std::string name);
  void listPolicies();
  void setBudgetPolicy(BudgetPolicy &policy);
  void enactPolicies();
private:
  std::map<std::string, double> taxRates;
  std::map<std::string, double> cityTaxes;
  std::vector<CityStructure> cities;
  BudgetPolicy *budgetPolicy = nullptr;
  std::map<std::string, Policy*> laws;
};

#endif
