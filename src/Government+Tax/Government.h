/**
 * @file Government.h
 * @brief Header file for the Government class, which manages tax collection and budget allocation for cities.
 * @details This file defines the Government class, responsible for collecting taxes from various city structures,
 * managing budget policies, and allocating funds to different departments within each city.
 * The class allows setting specific tax rates for categories and applying budget policies for optimal resource distribution.
 * @author WORKONMYMACHINE TEAM
 */
#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "CityStructure.h"
#include "BudgetPolicy.h"
#include <string>
#include <map>
#include <vector>

class CitezenTaxAB;
class Policy;
/**
 * @class Government
 * @brief Represents a government entity responsible for managing taxes and budgets for cities.
 */
class Government
{
public:
    /**
     * @brief Processes taxes for the specified city structure.
     * @param city The city structure on which to process taxes.
     */
  void processTaxes(CityStructure &city);
  /**
     * @brief Applies the current budget policy to the specified city structure.
     * @param city The city structure to which the budget is applied.
     */
  void applyBudget(CityStructure &city);
  /**
     * @brief Sets the tax rate for the specified category.
     * @param category The category for which the tax rate is set.
     * @param rate The tax rate to set.
     */
  void setTaxRate(std::string category, double rate);
  /**
     * @brief Collects taxes based on current tax rates.
     */
  void collectTaxes();
   /**
     * @brief Allocates collected taxes to a specified department.
     * @param department The department to receive the allocation.
     * @param amount The amount to allocate.
     */
  void allocateTaxes(std::string department, double amount);
  /**
     * @brief Adds a city to the government’s management.
     * @param city The CityStructure to add.
     */
  void addCity(CityStructure &city);
  /**
     * @brief Sets the current budget policy.
     * @param policy The BudgetPolicy to set.
     */
  void setBudgetPolicy(BudgetPolicy &policy);
private:
  std::map<std::string, double> taxRates;
  std::map<std::string, double> cityTaxes;
  std::vector<CityStructure> cities;
  BudgetPolicy *budgetPolicy = nullptr;
};

#endif
