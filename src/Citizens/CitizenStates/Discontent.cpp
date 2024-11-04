#include "Discontent.h"
#include "Upset.h"
#include "Indifferent.h"

CitizenState *Discontent::handleChange(int change)
{
    if (change > 0)
    {
        return new Indifferent();
    }
    else if (change < 0)
    {
        return new Upset();
    }

    return this;
}

std::string Discontent::getState()
{
    return "Discontent";
}