#include <iostream>
#include "TransportInclude.h"

void testRoadComponent(RoadComponent *roadComponent)
{
    std::cout << " - Testing Road Component:" << std::endl;
    std::cout << "\t - Displaying Info:" << std::endl;
    roadComponent->displayInfo();
    std::cout << "\t - Calculating Traffic:" << std::endl;
    roadComponent->calculateTraffic();
    std::cout << "\t - Getting Distance:" << std::endl;
    roadComponent->getDistance();
    std::cout << "\t - Testing Complete!" << std::endl;
}

void testRoads()
{
    std::cout << "############################################" << std::endl;
    std::cout << "Testing Road Components" << std::endl;
    std::cout << "############################################" << std::endl;
    CityMediator *mediator = new CityMediator();
    std::cout << " - CityMediator created!" << std::endl;

    RoadComponent **roads = new RoadComponent *[4];
    roads[0] = new MainRoads(mediator);
    roads[1] = new Highways(mediator);
    roads[2] = new RoadsComposite(mediator);
    roads[3] = new ResidentialStreets(mediator);
    std::cout << " - Roads created!" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        testRoadComponent(roads[i]);
    }
}

int main()
{
    testRoads();
    return 0;
}