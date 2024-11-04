#include "Content.h"
#include "Indifferent.h"
#include "Happy.h"
#include <memory>

std::unique_ptr<CitizenState> Content::handleChange(int change)
{
    if (change > 0)
    {
        return std::make_unique<Happy>();
    }
    else if (change < 0)
    {
        return std::make_unique<Indifferent>();
    }

    return std::make_unique<Content>();
}

std::string Content::getState()
{
    return "Content";
}
