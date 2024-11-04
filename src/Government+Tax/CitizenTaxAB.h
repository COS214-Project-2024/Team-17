#ifndef CITIZENTAXAB_H
#define CITIZENTAXAB_H

#include "TaxAndBudgetVisitor.h"

class citizen;
class building;
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
     * @param citizen The Citizen object being visited.
     * @return The calculated tax amount.
     */
	double visit(Citizen *citizen);
    /**
     * @brief Visits a Building object and calculates the tax.
     * @param business The Building object being visited.
     * @return The calculated tax amount.
     */
	double visit(Building *business);
};

#endif
