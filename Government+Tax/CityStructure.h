#ifndef CITYSTRUCTURE_H
#define CITYSTRUCTURE_H

#include "CityBlock.h"
#include "TaxAndBudgetVisitor.h"
#include <vector>

class CityStructure {
private:
  std::string Name;
	std::vector<CityBlock*> blocks;
  std::map<std::string, double> departments;
public:
  CityStructure(std::string name);
	void accept(TaxAndBudgetVisitor* visitor);
	void addBlock(CityBlock* block);
  void allocateBudget(std::string dept , double amount);
  double getIncome();
  std::string getName();
};

#endif
