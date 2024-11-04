#include "../src/Transport/TransportInclude.h"
#include "../src/Citizens/CitizensIncludes.h"
#include "../src/Buildings/ResFlat.h"
#include "../src/Buildings/ComOffice.h"
#include "../colours.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(TestConnections, TestCompositeConnections)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    RoadComponent *highway = new RoadsComposite(0, 0, 150, 0, "highway");

    RoadComponent *mainRoad = new RoadsComposite(0, 0, 50, 20, "main");
    RoadComponent *residentialStreet = new RoadsComposite(60, 0, 50, 30, "residential");

    highway->addConnection(mainRoad, 0);
    highway->addConnection(residentialStreet, 60);

    std::vector<RoadComponent *> connections = highway->getConnections();
    EXPECT_EQ(connections.size(), 4);

    delete mediator;
}

TEST(PointDistance, CheckRoadPointDistance)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    RoadComponent *residentialStreet = new RoadsComposite(0, 0, 90, 0, "residential");
    int x = 5;
    int y = 5;
    float val = 5;
    float dist = residentialStreet->calculateDistance(x, y);

    bool distInRange = abs(dist - val) < 0.0001;
    EXPECT_TRUE(distInRange);

    int x1 = 0;
    int y1 = 0;
    float val1 = 0;
    float dist1 = residentialStreet->calculateDistance(x1, y1);

    bool distInRange1 = abs(dist1 - val1) < 0.0001;
    EXPECT_TRUE(distInRange1);

    int x2 = 10;
    int y2 = 0;
    float val2 = 0;
    float dist2 = residentialStreet->calculateDistance(x2, y2);

    bool distInRange2 = abs(dist2 - val2) < 0.0001;
    EXPECT_TRUE(distInRange2);

    delete mediator;
}

TEST(CompositeTest, CheckCompositeLength)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 100, 100, "highway");
    roadsComposite->displayInfo();

    float val = 141.421356237;
    bool roadsCompositeInRange = abs(roadsComposite->getDistance() - val) < 0.0001;
    EXPECT_TRUE(roadsCompositeInRange);

    std::vector<RoadComponent *> components = roadsComposite->getComponents();
    EXPECT_EQ(components.size(), 2);

    delete mediator;
}

TEST(ConstructorTest, CheckDistance)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    RoadsComposite *highway = new RoadsComposite(0, 0, 10, 10, "highway");
    RoadsComposite *mainRoad = new RoadsComposite(0, 0, 10, 10, "main");
    RoadsComposite *residentialStreet = new RoadsComposite(0, 0, 10, 10, "residential");
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 10, 10, "highway");

    highway->displayInfo();
    mainRoad->displayInfo();
    residentialStreet->displayInfo();
    roadsComposite->displayInfo();

    float val = 14.1421356237;

    bool highwayInRange = abs(highway->getDistance() - val) < 0.0001;
    bool mainRoadInRange = abs(mainRoad->getDistance() - val) < 0.0001;
    bool residentialStreetInRange = abs(residentialStreet->getDistance() - val) < 0.0001;
    bool roadsCompositeInRange = abs(roadsComposite->getDistance() - val) < 0.0001;

    EXPECT_TRUE(highwayInRange);
    EXPECT_TRUE(mainRoadInRange);
    EXPECT_TRUE(residentialStreetInRange);
    EXPECT_TRUE(roadsCompositeInRange);

    delete mediator;
}

TEST(BuildingConnectionTest, CheckBuildingConnection)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 100, 0, "highway");
    Building *building = new ResFlat();
    building->setXCoordinate(0);
    building->setYCoordinate(CityCentralMediator::BUILDING_ROAD_DISTANCE - 1);

    bool canReach = mediator->isReachableByRoad(building->getXCoordinate(), building->getYCoordinate());
    EXPECT_TRUE(canReach);

    building->setYCoordinate(CityCentralMediator::BUILDING_ROAD_DISTANCE + 1);
    canReach = mediator->isReachableByRoad(building->getXCoordinate(), building->getYCoordinate());
    EXPECT_FALSE(canReach);

    delete mediator;
}

TEST(CitizenCarTransport, CitizenCarTransport)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 500, 0, "highway");
    Building *home = new ResFlat();
    home->setXCoordinate(0);
    home->setYCoordinate(CityCentralMediator::BUILDING_ROAD_DISTANCE - 1);

    Building *workplace = new ComOffice();
    workplace->setXCoordinate(500);
    workplace->setYCoordinate(CityCentralMediator::BUILDING_ROAD_DISTANCE - 1);

    Citizen *citizen = new Citizen();
    citizen->setWorkplace(workplace);
    citizen->setHome(home);

    citizen->giveCar();

    mediator->citizensStartWork();

    for (int i = 0; i < 20; i++)
    {
        mediator->updateBuses();
        mediator->citizensDoSomething();
    }

    EXPECT_EQ(citizen->getCurrentBuilding(), workplace);

    delete mediator;
}

TEST(TestBlockedRoads, TestBlockedRoads)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 500, 0, "residential");
    Building *home = new ResFlat();
    home->setXCoordinate(0);
    home->setYCoordinate(0);
    RoadComponent *homeRoad = mediator->getClosestRoad(home->getXCoordinate(), home->getYCoordinate());
    std::cout << "Home road: ";
    homeRoad->displayInfo();

    Building *workplace = new ComOffice();
    workplace->setXCoordinate(500);
    workplace->setYCoordinate(0);

    Citizen *citizen = new Citizen();
    citizen->setWorkplace(workplace);
    citizen->setHome(home);

    citizen->giveCar();

    mediator->citizensStartWork();

    Bus *bus1 = new Bus(roadsComposite->getComponents()[2], 10);
    Bus *bus2 = new Bus(roadsComposite->getComponents()[2], 10);

    for (int i = 0; i < 10; i++)
    {
        mediator->updateBuses();
        mediator->citizensDoSomething();
    }

    // EXPECT_NE(citizen->getCurrentBuilding(), workplace);

    delete mediator;
}

void testRouteCalculationSimple()
{
    std::cout << "Create mediator" << std::endl;
    CityCentralMediator *mediator = CityCentralMediator::getInstance();
    std::cout << "Create road" << std::endl;
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 100, 100, "highway");
    std::cout << "Calculate route" << std::endl;
    std::vector<RoadComponent *> route = mediator->calculateRoute(0, 0, 100, 100);

    std::cout << "Route:" << std::endl;
    std::cout << "Start: 0, 0" << std::endl;
    for (auto road : route)
    {
        std::cout << YELLOW;
        road->displayInfo();
        std::cout << RESET;
    }
    std::cout << "End: 100, 100" << std::endl;

    delete mediator;
}

// /*

// +---+---+---+
// |   |   |   |
// +---+---+---+
// |   |   |   |
// +---+---+---+
// |   |   |   |
// +---+---+---+

// */

void testRouteCalculationComplex()
{
    std::cout << "Create mediator" << std::endl;
    CityCentralMediator *mediator = CityCentralMediator::getInstance();

    // Create arrays for horizontal and vertical roads
    RoadsComposite ***horizontalRoads = new RoadsComposite **[4];
    RoadsComposite ***verticalRoads = new RoadsComposite **[4];

    // Initialize arrays
    for (int i = 0; i < 4; i++)
    {
        horizontalRoads[i] = new RoadsComposite *[3]; // 3 horizontal roads per row
        verticalRoads[i] = new RoadsComposite *[4];   // 4 vertical roads per column
    }

    // Create horizontal roads
    for (int i = 0; i < 4; i++)
    { // rows
        for (int j = 0; j < 3; j++)
        { // columns
            horizontalRoads[i][j] = new RoadsComposite(
                j * 100,       // startX
                i * 100,       // startY
                (j + 1) * 100, // endX
                i * 100,       // endY
                "highway");
        }
    }

    // Create vertical roads
    for (int i = 0; i < 3; i++)
    { // rows
        for (int j = 0; j < 4; j++)
        { // columns
            verticalRoads[i][j] = new RoadsComposite(
                j * 100,       // startX
                i * 100,       // startY
                j * 100,       // endX
                (i + 1) * 100, // endY
                "highway");
        }
    }

    // Connect horizontal roads to each other
    for (int i = 0; i < 4; i++)
    { // rows
        for (int j = 0; j < 2; j++)
        { // columns
            horizontalRoads[i][j]->addConnection(horizontalRoads[i][j + 1], 100);
            horizontalRoads[i][j + 1]->addConnection(horizontalRoads[i][j], 100);
        }
    }

    // Connect vertical roads to each other
    for (int i = 0; i < 2; i++)
    { // rows
        for (int j = 0; j < 4; j++)
        { // columns
            verticalRoads[i][j]->addConnection(verticalRoads[i + 1][j], 100);
            verticalRoads[i + 1][j]->addConnection(verticalRoads[i][j], 100);
        }
    }

    // Connect horizontal and vertical roads at intersections
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Connect with vertical road below (if exists)
            if (i < 3)
            {
                horizontalRoads[i][j]->addConnection(verticalRoads[i][j], 100);
                horizontalRoads[i][j]->addConnection(verticalRoads[i][j + 1], 100);
                verticalRoads[i][j]->addConnection(horizontalRoads[i][j], 100);
                verticalRoads[i][j + 1]->addConnection(horizontalRoads[i][j], 100);
            }
            // Connect with vertical road above (if exists)
            if (i > 0)
            {
                horizontalRoads[i][j]->addConnection(verticalRoads[i - 1][j], 100);
                horizontalRoads[i][j]->addConnection(verticalRoads[i - 1][j + 1], 100);
                verticalRoads[i - 1][j]->addConnection(horizontalRoads[i][j], 100);
                verticalRoads[i - 1][j + 1]->addConnection(horizontalRoads[i][j], 100);
            }
        }
    }

    std::cout << "Calculate route" << std::endl;
    std::vector<RoadComponent *> route = mediator->calculateRoute(0, 0, 300, 300);

    std::cout << "Route:" << std::endl;
    std::cout << "Start: 0, 0" << std::endl;
    for (auto road : route)
    {
        std::cout << YELLOW;
        road->displayInfo();
        std::cout << RESET;
    }
    std::cout << "End: 300, 300" << std::endl;

    // Cleanup
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // delete horizontalRoads[i][j];
        }
        delete[] horizontalRoads[i];
    }
    delete[] horizontalRoads;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // delete verticalRoads[i][j];
        }
        delete[] verticalRoads[i];
    }
    delete[] verticalRoads;

    delete mediator;
}

int main()
{
    testRouteCalculationSimple();
    // testRouteCalculationComplex();
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}