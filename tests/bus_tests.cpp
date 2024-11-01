#include <gtest/gtest.h>

#include "../src/Citizens/CitizensIncludes.h"
#include "../src/Transport/TransportInclude.h"
#include "../src/Buildings/ResFlat.h"

TEST(Bus, TestRequestBus)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();

    RoadsComposite *road = new RoadsComposite(0, 0, 300, 0, "highway");

    Bus *bus = new Bus(road, 10);

    Citizen *citizen = new Citizen();

    ResFlat *home = new ResFlat();
    home->setXCoordinate(300);
    home->setYCoordinate(10);
    ResFlat *workplace = new ResFlat();
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