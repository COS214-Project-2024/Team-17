#include "Happy.h"
#include "Content.h"

CitizenState *Happy::handleChange(int change)
{
    if (change <= 0)
    {
        return new Content();
    }
    return new Happy();
}

std::string Happy::getState()
{
    return "Happy";
}