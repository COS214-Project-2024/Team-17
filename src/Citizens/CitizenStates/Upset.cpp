#include "Upset.h"
#include "Discontent.h"

CitizenState *Upset::handleChange(int change)
{
    if (change > 0)
    {
        return new Discontent();
    }
    else
    {
        return this;
    }
}

std::string Upset::getState()
{
    return "Upset";
}