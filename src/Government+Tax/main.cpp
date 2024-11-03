#include "Government.h"
#include "CityStructure.h"
#include "HealthPolicy.h"
#include "InfrastructurePolicy.h"
#include "AllocateTaxCommand.h"
#include "CollectTaxCommand.h"
#include "SetTaxRateCommand.h"
#include "TaxManager.h"
#include "CitizenTaxAB.h"
#include <iostream>

int main()
{
  std::cout << "\n==Creation==\n";
  Government gov;
  CityStructure city("Pretoria");
  gov.addCity(city);

  Policy *policy = new HealthPolicy();

  std::cout << "\n==Policy==\n";
  gov.setPolicy(*policy);
  gov.applyBudget(city);
  policy = new InfrastructurePolicy();
  gov.setPolicy(*policy);
  gov.applyBudget(city);

  std::cout << "\n==Taxes==\n";
  gov.collectTaxes();

  std::cout << city.getIncome() << std::endl;

  std::cout << "\n==Comand Manager==\n";
  TaxCommand *allocateCommand = new AllocateTaxCommand(&gov, 100.0, "Military");
  TaxCommand *collectCommand = new CollectTaxCommand(&gov);
  TaxCommand *setRateCommand = new SetTaxRateCommand(&gov, 0.5, "Commercial");

  TaxManager manager;
  manager.executeCommand();
  manager.setCommand(allocateCommand);
  manager.executeCommand();
  manager.setCommand(collectCommand);
  manager.executeCommand();
  manager.setCommand(setRateCommand);
  manager.executeCommand();

  std::cout << "\n==Comand Handler==\n";
  TaxHandler *handler = gov.createTaxHandlerChain();
  handler->handleRequest(setRateCommand);

  std::cout << "\n==Visitor==\n";
  TaxAndBudgetVisitor *visitor = new CitizenTaxAB();
  city.accept(visitor);
}