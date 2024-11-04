#include <gtest/gtest.h>

#include "../src/Citizens/CitizensIncludes.h"
#include "../src/Transport/TransportInclude.h"
#include "../src/Buildings/ResFlat.h"
#include "../src/Buildings/ComMall.h"

TEST(Train, TestTrainTransport)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();

    RoadsComposite *road = new RoadsComposite(0, 0, 300, 0, "highway");

    Bus *bus = new Bus(road, 10);

    Citizen *citizen = new Citizen();

    ResFlat *home = new ResFlat();
    home->setXCoordinate(300);
    home->setYCoordinate(10);

    Trainstation *nearHome = new Trainstation(10);
    nearHome->setXCoordinate(300);
    nearHome->setYCoordinate(10);

    Trainstation *nearWork = new Trainstation(10);
    nearWork->setXCoordinate(0);
    nearWork->setYCoordinate(10);

    ComMall *workplace = new ComMall();
    workplace->setXCoordinate(0);
    workplace->setYCoordinate(10);

    citizen->setWorkplace(workplace);
    citizen->setHome(home);

    mediator->citizensStartWork();

    for (int i = 0; i < 20; i++)
    {
        mediator->updateBuses();
        mediator->citizensDoSomething();
    }

    ASSERT_EQ(citizen->getCurrentBuilding(), workplace);

    mediator->citizensEndWork();

    for (int i = 0; i < 20; i++)
    {
        mediator->updateBuses();
        mediator->citizensDoSomething();
    }

    ASSERT_EQ(citizen->getCurrentBuilding(), home);

    delete workplace;
    delete home;
    delete citizen;
    delete bus;
    delete road;
    delete mediator;
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}