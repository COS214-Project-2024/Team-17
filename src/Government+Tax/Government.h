#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "CityStructure.h"
#include "TaxHandler.h"
#include "TaxRateHandler.h"
#include "TaxAllocationHandler.h"
#include "TaxCollectionHandler.h"
#include "Policy.h"
#include <string>
#include <map>
#include <vector>

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
  TaxHandler *createTaxHandlerChain();

private:
  std::map<std::string, double> taxRates;
  std::map<std::string, double> cityTaxes;
  std::vector<CityStructure> cities;
  Policy *policy = nullptr;
};

#endif
