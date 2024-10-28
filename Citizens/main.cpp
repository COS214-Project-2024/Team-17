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
    citizen->setState(Happy());
    citizen->setState(Content());
    citizen->setState(Indifferent());
    citizen->setState(Discontent());
    citizen->setState(Upset());
    std::cout << " - Testing Complete!" << std::endl;
}

int main()
{
    testCitizens();
    return 0;
}