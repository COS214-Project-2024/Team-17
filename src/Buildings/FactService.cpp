#include "FactService.h"

FactService::FactService()
{
    cout << BLACK << "\t->Service factory created" << RESET << endl;
}

Services *FactService::createServiceBuilding(string type)
{
    if (type == "Education")
    {
        return new ServEducation();
    }
    else if (type == "Security")
    {
        return new ServSecurity();
    }
    else if (type == "Entertainment")
    {
        return new ServEntertainment();
    }
    else if (type == "Hospital")
    {
        return new ServHospital();
    }
    return nullptr;
}

Residential *FactService::createResBuilding(string type)
{
    if (type == "House")
    {
        return nullptr;
    }
    else if (type == "Townhouse")
    {
        return nullptr;
    }
    else if (type == "Flat")
    {
        return nullptr;
    }
    else if (type == "Estate")
    {
        return nullptr;
    }
    return nullptr;
}

Commercial *FactService::createComBuilding(string type)
{
    if (type == "Mall")
    {
        return nullptr;
    }
    else if (type == "Shop")
    {
        return nullptr;
    }
    else if (type == "Office")
    {
        return nullptr;
    }
    return nullptr;
}
Industrial *FactService::createIndBuilding(string type)
{
    if (type == "Factory")
    {
        return nullptr;
    }
    else if (type == "Warehouse")
    {
        return nullptr;
    }
    else if (type == "Plant")
    {
        return nullptr;
    }
    return nullptr;
}
Landmark *FactService::createLandmark(string type)
{
    if (type == "Park")
    {
        return nullptr;
    }
    else if (type == "Community Center")
    {
        return nullptr;
    }
    else if (type == "Monument")
    {
        return nullptr;
    }
    return nullptr;
}