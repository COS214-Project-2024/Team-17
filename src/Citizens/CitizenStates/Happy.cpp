#include "Happy.h"
#include "Content.h"
#include <memory>

std::unique_ptr<CitizenState> Happy::handleChange(int change)
{
    if (change <= 0)
    {
        return std::make_unique<Content>();
    }
    return std::make_unique<Happy>();
}

std::string Happy::getState()
{
    return "Happy";
}
