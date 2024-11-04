/**
 * @file CitizenTaxAB.h
 * @brief Header file for the CitizenTaxAB class, which calculates tax for citizens and buildings.
 * @details This file defines the CitizenTaxAB class, implementing the TaxAndBudgetVisitor interface
 * to compute taxes for both Citizen and Building objects. The class provides a concrete visitor that
 * allows differentiated tax calculations for various city entities.
 * @see TaxAndBudgetVisitor for the base visitor interface this class implements.
 * @see Citizen for the class representing individual citizens.
 * @see Building for the class representing business buildings within the city.
 * @note This visitor is utilized in the Government tax collection process to aggregate city income.
 * @author WORKONMYMACHINE TEAM
 */
#ifndef CITIZENTAXAB_H
#define CITIZENTAXAB_H

#include "TaxAndBudgetVisitor.h"
#include <memory> // Include for smart pointers

class Citizen; // Updated to use correct casing
class Building; // Updated to use correct casing

/**
 * @class CitizenTaxAB
 * @brief Concrete visitor for calculating tax on citizens and buildings.
 *
 * This class implements the TaxAndBudgetVisitor interface to calculate taxes for citizens and buildings.
 */
class CitizenTaxAB : public TaxAndBudgetVisitor
{
public:
    /**
     * @brief Visits a Citizen object and calculates the tax.
     * @param citizen Shared pointer to the Citizen object being visited.
     * @return The calculated tax amount.
     */
    double visit(std::shared_ptr<Citizen> citizen); // Changed to smart pointer

    /**
     * @brief Visits a Building object and calculates the tax.
     * @param business Shared pointer to the Building object being visited.
     * @return The calculated tax amount.
     */
    double visit(std::shared_ptr<Building> business); // Changed to smart pointer
};

#endif // CITIZENTAXAB_H
