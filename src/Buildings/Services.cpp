#include "Services.h"

bool Services::getState()
{
    //  cout<<"commercial state"<<endl;
    return operational;
}

string Services::getBuildingType()
{
    return "Residential";
}

Services::Services(int citizensServed)
{
    this->citizensServed = citizensServed;
}

bool Services::checkBuildRequirements()
{
    // add implementation
    return true;
}

// Observer Design Pattern
void Services::addUtility(UtilityManager *utility)
{
    Utilities.push_back(utility);
    std::cout << this->getBuildingType() << " Has Utility Connection of type:" << utility->getType() << std::endl;
}

void Services::removeUtility(UtilityManager *utility)
{
    auto it = Utilities.begin();
    while (it != Utilities.end())
    {
        if (*it == utility)
        {
            Utilities.erase(it);
            std::cout << "Utility Deconstruction of type:" << utility->getType() << std::endl;
            return;
        }
        ++it;
    }
}

void Services::notifyUtilities()
{
    for (UtilityManager *utility : Utilities)
    {
        utility->update(this);
    }
}

bool Services::moveIn(Citizen *resident)
{
    return true;
}

void Services::moveOut(Citizen *resident)
{
    return;
}

int Services::getCitizenServed()
{
    return citizensServed;
}
