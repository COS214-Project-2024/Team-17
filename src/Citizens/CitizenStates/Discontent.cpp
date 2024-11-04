#include "Discontent.h"
#include "Indifferent.h"
#include "Upset.h"
#include <memory>

std::unique_ptr<CitizenState> Discontent::handleChange(int change)
{
    if (change > 0)
    {
        return std::make_unique<Indifferent>();
    }
    else if (change < 0)
    {
        return std::make_unique<Upset>();
    }

    return std::make_unique<Discontent>();
}

std::string Discontent::getState()
{
    return "Discontent";
}
