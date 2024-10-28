#include <iostream>
#include "CitizensIncludes.h"

void testCitizens()
{
    std::cout << "############################################" << std::endl;
    std::cout << "Testing Citizens" << std::endl;
    std::cout << "############################################" << std::endl;
    CityMediator *mediator = new CityCentralMediator();
    Citizen *citizen = new Citizen(mediator);
    std::cout << " - Citizen " << citizen->getName() << " created" << std::endl;
    std::cout << " - Testing Citizen State" << std::endl;
    citizen->setState(new Happy());
    citizen->setState(new Content());
    citizen->setState(new Indifferent());
    citizen->setState(new Discontent());
    citizen->setState(new Upset());
    std::cout << " - Testing Complete!" << std::endl;
    delete citizen;
    delete mediator;
}

int main()
{
    testCitizens();
    return 0;
}