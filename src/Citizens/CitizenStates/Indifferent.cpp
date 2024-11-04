#include "Indifferent.h"
#include "Discontent.h"
#include "Content.h"
#include <memory>
std::unique_ptr<CitizenState> Indifferent::handleChange(int change)
{
    if (change > 0)
    {
        return std::make_unique<Content>(); // Use std::make_unique
    }
    else if (change < 0)
    {
        return std::make_unique<Discontent>(); // Use std::make_unique
    }

    return std::make_unique<Indifferent>(); // Use std::make_unique
}

std::string Indifferent::getState()
{
    return "Indifferent";
}