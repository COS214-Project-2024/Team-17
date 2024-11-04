#ifndef CITYBLOCK_H
#define CITYBLOCK_H

#include "CityMediator.h"
#include <string>
#include <memory> // Include for smart pointers

class TaxAndBudgetVisitor;

/**
 * @class CityBlock
 * @brief Base class representing a block within the city.
 *
 * The CityBlock class serves as a base for various types of city blocks,
 * providing a mechanism to interact with the CityMediator and accept
 * visitors that perform operations such as tax and budget assessments.
 */
class CityBlock
{
protected:
    std::shared_ptr<CityMediator> mediator; ///< Smart pointer to the CityMediator managing this block.

public:
    /**
     * @brief Constructor for the CityBlock class.
     */
    CityBlock() : mediator(nullptr) {} // Initialize mediator to nullptr

    /**
     * @brief Accepts a TaxAndBudgetVisitor to perform operations on this city block.
     * @param visitor A pointer to the visitor that will perform operations.
     * @return A double representing the result of the visitor's operation.
     */
    double accept(TaxAndBudgetVisitor *visitor);
};

#endif // CITYBLOCK_H
