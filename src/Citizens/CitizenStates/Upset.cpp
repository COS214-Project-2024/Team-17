#include "Upset.h"
#include "Discontent.h"

std::unique_ptr<CitizenState> Upset::handleChange(int change)
{
    if (change > 0)
    {
        return std::make_unique<Discontent>(); // Use std::make_unique
    }
    return std::make_unique<Upset>(); // Use std::make_unique
}

std::string Upset::getState()
{
    return "Upset";
}