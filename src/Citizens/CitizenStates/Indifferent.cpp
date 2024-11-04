#include "Indifferent.h"
#include "Discontent.h"
#include "Content.h"

CitizenState *Indifferent::handleChange(int change)
{
    if (change > 0)
    {
        return new Content();
    }
    else if (change < 0)
    {
        return new Discontent();
    }

    return this;
}

std::string Indifferent::getState()
{
    return "Indifferent";
}