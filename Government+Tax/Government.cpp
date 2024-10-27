#include "Government.h"

void Government::processTaxes(CityStructure& city) {
  double income = city.getIncome();
  double totalTax = 0;

  for(const auto& [category, rate] : taxRates) {
    double taxforCategory = income * rate;
    totalTax += taxforCategory;
  }

  cityTaxes[city.getName()] += totalTax;
}

void Government::applyBudget(CityStructure& city) {
  this->policy->applyBudget(city, cityTaxes[city.getName()]);
}

void Government::setPolicy(Policy& policy)
{
  this->policy = &policy;
}

void Government::setTaxRate(std::string category, double rate) {
  taxRates[category] = rate;
}

void Government::collectTaxes() {
  for (CityStructure& citystructure : cities) {
    processTaxes(citystructure);
  }
}

void Government::addCity(CityStructure& city) {
  this->cities.push_back(city);
}

void Government::allocateTaxes(std::string department, double amount) {
	// TODO - implement Government::allocateTaxes
	throw "Not yet implemented";
}

TaxHandler* Government::createTaxHandlerChain() {
  TaxRateHandler* rateHandler = new TaxRateHandler();
  TaxCollectionHandler* collectionHanlder = new TaxCollectionHandler();
  TaxAllocationHandler* allocationHandler = new TaxAllocationHandler();

  rateHandler->setNext(collectionHanlder);
  collectionHanlder->setNext(allocationHandler);
  return rateHandler;
}
