#ifndef CITYSTRUCTURE_H
#define CITYSTRUCTURE_H

#include "CityBlock.h"
#include <vector>
#include <string>
#include <map>

class CityStructure {
private:
  std::string Name;
	std::vector<CityBlock*> blocks;
  std::map<std::string, double> departments;
public:
  CityStructure(std::string name);
	void addBlock(CityBlock* block);
  void allocateBudget(std::string dept , double amount);
  double getIncome();
  std::string getName();
};

#endif
