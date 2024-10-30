#ifndef CITYSTRUCTURE_H
#define CITYSTRUCTURE_H

class TaxAndBudgetVisitor;

class CityBlock;
#include <vector>
#include <string>
#include <map>

class CityStructure
{
private:
  std::string Name;
  std::vector<CityBlock *> blocks;
  std::map<std::string, double> departments;
  double income;

public:
  CityStructure(std::string name);
  void accept(TaxAndBudgetVisitor *visitor);
  void addBlock(CityBlock *block);
  void allocateBudget(std::string dept, double amount);
  double getIncome();
  std::string getName();
};

#endif
