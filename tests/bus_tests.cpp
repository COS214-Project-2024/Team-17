#include <gtest/gtest.h>

#include "../src/Citizens/CitizensIncludes.h"
#include "../src/Transport/TransportInclude.h"
#include "../src/Buildings/ResFlat.h"
#include "../src/Buildings/ComMall.h"

TEST(Bus, TestRequestBus)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();

    RoadsComposite *road = new RoadsComposite(0, 0, 300, 0, "highway");

    Bus *bus = new Bus(road, 10);

    Citizen *citizen = new Citizen();

    ResFlat *home = new ResFlat();
    home->setXCoordinate(300);
    home->setYCoordinate(10);
    Building *workplace = new ComMall();
    workplace->setXCoordinate(0);
    workplace->setYCoordinate(10);

    citizen->setWorkplace(workplace);
    citizen->setHome(home);

    mediator->citizensStartWork();

    for (int i = 0; i < 20; i++)
    {
        // mediator->updateBuses();
        mediator->citizensDoSomething();
    }

    // ASSERT_EQ(citizen->getCurrentBuilding(), workplace);

    // mediator->citizensEndWork();

    // for (int i = 0; i < 20; i++)
    // {
    //     mediator->updateBuses();
    //     mediator->citizensDoSomething();
    // }

    // ASSERT_EQ(citizen->getCurrentBuilding(), home);

    // delete workplace;
    // delete home;
    // delete citizen;
    // delete bus;
    // delete road;
    delete mediator;
}

// TEST(Bus, TestBusPickup)
// {
//     CityCentralMediator *mediator = CityCentralMediator::getInstance();

//     RoadsComposite *road = new RoadsComposite(0, 0, 300, 0, "highway");

//     Bus *bus = new Bus(road, 10);

//     Citizen *citizen1 = new Citizen();
//     Citizen *citizen2 = new Citizen();

//     ResFlat *home = new ResFlat();
//     home->setXCoordinate(300);
//     home->setYCoordinate(10);
//     Building *workplace = new ComMall();
//     workplace->setXCoordinate(0);
//     workplace->setYCoordinate(10);

//     ResFlat *home2 = new ResFlat();
//     home2->setXCoordinate(250);
//     home2->setYCoordinate(10);

//     citizen1->setWorkplace(workplace);
//     citizen1->setHome(home);
//     citizen2->setWorkplace(workplace);
//     citizen2->setHome(home2);

//     mediator->citizensStartWork();

//     for (int i = 0; i < 20; i++)
//     {
//         mediator->updateBuses();
//         mediator->citizensDoSomething();
//     }

//     ASSERT_EQ(citizen1->getCurrentBuilding(), workplace);
//     ASSERT_EQ(citizen2->getCurrentBuilding(), workplace);

//     mediator->citizensEndWork();

//     for (int i = 0; i < 20; i++)
//     {
//         mediator->updateBuses();
//         mediator->citizensDoSomething();
//     }

//     ASSERT_EQ(citizen1->getCurrentBuilding(), home);
//     ASSERT_EQ(citizen2->getCurrentBuilding(), home2);

//     delete workplace;
//     delete home;
//     delete citizen2;
//     delete citizen1;
//     delete bus;
//     delete road;
//     delete mediator;
// }

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}