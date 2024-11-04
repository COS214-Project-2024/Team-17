#include <iostream>
#include "../src/Citizens/Citizen.h"
#include "../src/Citizens/CityCentralMediator.h"

int main()
{
    std::cout << "Create a citizen and mediator" << std::endl;
    CityCentralMediator *m = CityCentralMediator::getInstance();
    std::cout << " - Mediator created" << std::endl;
    Citizen *citizen = new Citizen();
    std::cout << "Created:" << std::endl;
    std::cout << " - Citizen " << citizen->getName() << " created" << std::endl;
    std::cout << "Citizen deleted" << std::endl;

    // Citizen *citizen2 = new Citizen();
    delete m;
    return 0;
}