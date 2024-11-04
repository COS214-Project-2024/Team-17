#include "Happy.h"
#include "Content.h"

CitizenState *Happy::handleChange(int change)
{
    if (change <= 0)
    {
        return new Content();
    }
    return this;
}

std::string Happy::getState()
{
    return "Happy";
}