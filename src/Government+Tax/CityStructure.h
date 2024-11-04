/**
 * @file CityStructure.h
 * @brief Header file for the CityStructure class, representing a city with blocks and departments for budget allocation.
 * @details This file defines the CityStructure class, which models a city’s structure, including its blocks and departments.
 * It supports tax processing and budget allocation to various departments, integrating with visitor classes for tax and budget management.
 * The CityStructure class interacts with Government and policy classes to apply city-specific budgeting rules.
 * @author WORKONMYMACHINE TEAM
 */
#ifndef CITYSTRUCTURE_H
#define CITYSTRUCTURE_H

class TaxAndBudgetVisitor;

class CityBlock;
#include <vector>
#include <string>
#include <map>
/**
 * @class CityStructure
 * @brief Represents a city's structure, containing blocks, departments, and income information.
 */
class CityStructure
{
private:
  std::string Name;
  std::vector<CityBlock *> blocks;
  std::map<std::string, double> departments;
  double income;

public:
  /**
   * @brief Constructs a new CityStructure with the given name.
   * @param name The name of the city structure.
   */
  CityStructure(std::string name);
  /**
   * @brief Accepts a TaxAndBudgetVisitor for processing taxes or budgets.
   * @param visitor The visitor used for processing.
   */
  void accept(TaxAndBudgetVisitor *visitor);
  /**
   * @brief Adds a city block to the structure.
   * @param block The CityBlock to add.
   */
  void addBlock(CityBlock *block);

  /**
   * @brief Allocates a specified budget to a department.
   * @param dept The department name.
   * @param amount The amount to allocate.
   */
  void allocateBudget(std::string dept, double amount);
  /**
   * @brief Gets the income of the city structure.
   * @return The income of the city.
   */
  double getIncome();
  /**
   * @brief Gets the name of the city structure.
   * @return The name of the city.
   */
  std::string getName();

  ~CityStructure();
};

#endif
