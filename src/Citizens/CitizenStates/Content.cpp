#include "Content.h"
#include "Indifferent.h"
#include "Happy.h"

CitizenState *Content::handleChange(int change)
{
    if (change > 0)
    {
        return new Happy();
    }
    else if (change < 0)
    {
        return new Indifferent();
    }

    return this;
}

std::string Content::getState()
{
    return "Content";
}