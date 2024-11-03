#include "Residential.h"

bool Residential::getState()
{
    //  cout<<"commercial state"<<endl;
    return operational;
}

string Residential::getBuildingType()
{
    return "Residential";
}

bool Residential::checkBuildRequirements()
{
    // add implementation
    return true;
}

// Observer Design Pattern
void Residential::addUtility(UtilityManager *utility)
{
    Utilities.push_back(utility);
    cout << this->getBuildingType() << " Has Utility Connection of type:" << utility->getType() << std::endl;
}

void Residential::removeUtility(UtilityManager *utility)
{
    auto it = Utilities.begin();
    while (it != Utilities.end())
    {
        if (*it == utility)
        {
            Utilities.erase(it);
            cout << "Utility Deconstruction of type:" << utility->getType() << std::endl;
            return;
        }
        ++it;
    }
}

void Residential::notifyUtilities()
{
    for (UtilityManager *utility : Utilities)
    {
        utility->update(this);
    }
}

bool Residential::addEmployee(Citizen *employee)
{
    return true;
}

void Residential::removeEmployee(Citizen *employee)
{
}

bool Residential::hasJob()
{
    return false;
}
