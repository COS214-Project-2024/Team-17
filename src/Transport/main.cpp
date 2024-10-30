#include <iostream>
#include "TransportInclude.h"
#include "../Citizens/CityCentralMediator.h"
// #include "../Citizens/CitizensIncludes.h"

void testRoadComponent(RoadComponent *roadComponent)
{
    std::cout << " - Testing Road Component:" << std::endl;
    std::cout << "\t - Displaying Info" << std::endl;
    roadComponent->displayInfo();
    std::cout << "\t - Calculating Traffic" << std::endl;
    roadComponent->calculateTraffic();
    std::cout << "\t - Getting Distance" << std::endl;
    roadComponent->getDistance();
    std::cout << "\t - Testing Complete!" << std::endl;
}

void testRoads()
{
    std::cout << "############################################" << std::endl;
    std::cout << "Testing Road Components" << std::endl;
    std::cout << "############################################" << std::endl;
    CityMediator *mediator = new CityCentralMediator();
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

void testRoadsIterator()
{
    std::cout << "############################################" << std::endl;
    std::cout << "Testing Road Iterators" << std::endl;
    std::cout << "############################################" << std::endl;
    CityMediator *mediator = new CityCentralMediator();
    std::cout << " - CityMediator created!" << std::endl;

    std::vector<RoadComponent *> roads = {new MainRoads(mediator), new Highways(mediator), new RoadsComposite(mediator), new ResidentialStreets(mediator)};

    RoadIterator *iterator = new RoadIteratorCon(&roads);

    std::cout << " - Testing Road Iterator:" << std::endl;
    std::cout << "\t - First" << std::endl;
    iterator->first();
    std::cout << "\t - Next" << std::endl;
    iterator->next();
    std::cout << "\t - Is Done" << std::endl;
    iterator->isDone();
    std::cout << "\t - Current Road" << std::endl;
    iterator->currentRoad();
    std::cout << "\t - Testing Complete!" << std::endl;
}

void testRoadsComposite()
{
    std::cout << "############################################" << std::endl;
    std::cout << "Testing Road Composite" << std::endl;
    std::cout << "############################################" << std::endl;
    CityMediator *mediator = new CityCentralMediator();
    std::cout << " - CityMediator created!" << std::endl;

    RoadsComposite *roadsComposite = new RoadsComposite(mediator);
    std::cout << " - Roads Composite created!" << std::endl;

    RoadComponent **roads = new RoadComponent *[4];
    roads[0] = new MainRoads(mediator);
    roads[1] = new Highways(mediator);
    roads[2] = new RoadsComposite(mediator);
    roads[3] = new ResidentialStreets(mediator);
    std::cout << " - Roads created!" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        roadsComposite->add(roads[i]);
    }
    std::cout << " - Roads added to composite!" << std::endl;

    std::cout << " - Testing Road Composite:" << std::endl;
    std::cout << "\t - Displaying Info" << std::endl;
    roadsComposite->displayInfo();
    std::cout << "\t - Calculating Traffic" << std::endl;
    roadsComposite->calculateTraffic();
    std::cout << "\t - Getting Distance" << std::endl;
    roadsComposite->getDistance();
    roadsComposite->remove(roads[0]);
    std::cout << " - Road removed from composite!" << std::endl;
    std::cout << "\t - Testing Complete!" << std::endl;
}

int main()
{
    testRoads();
    testRoadsIterator();
    testRoadsComposite();
    return 0;
}