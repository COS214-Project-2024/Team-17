#include "../src/Transport/TransportInclude.h"
#include "../src/Citizens/CitizensIncludes.h"
#include "../colours.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(TestConnections, TestCompositeConnections)
{
    RoadComponent *highway = new RoadsComposite(0, 0, 150, 0, "highway");

    RoadComponent *mainRoad = new MainRoads(0, 0, 50, 20);
    RoadComponent *residentialStreet = new ResidentialStreets(60, 0, 50, 30);

    highway->addConnection(mainRoad, 0);
    highway->addConnection(residentialStreet, 60);

    std::vector<RoadComponent *> connections = highway->getConnections();
    EXPECT_EQ(connections.size(), 4);
}

TEST(PointDistance, CheckRoadPointDistance)
{
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
}

TEST(CompositeTest, CheckCompositeLength)
{
    RoadsComposite *roadsComposite = new RoadsComposite(0, 0, 100, 100, "highway");
    roadsComposite->displayInfo();

    float val = 141.421356237;
    bool roadsCompositeInRange = abs(roadsComposite->getDistance() - val) < 0.0001;
    EXPECT_TRUE(roadsCompositeInRange);

    std::vector<RoadComponent *> components = roadsComposite->getComponents();
    EXPECT_EQ(components.size(), 2);
}

TEST(ConstructorTest, CheckDistance)
{
    Highways *highway = new Highways(0, 0, 10, 10);
    MainRoads *mainRoad = new MainRoads(0, 0, 10, 10);
    ResidentialStreets *residentialStreet = new ResidentialStreets(0, 0, 10, 10);
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
}

/*


+---+---+---+
|   |   |   |
+---+---+---+
|   |   |   |
+---+---+---+
|   |   |   |
+---+---+---+

*/

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
            delete horizontalRoads[i][j];
        }
        delete[] horizontalRoads[i];
    }
    delete[] horizontalRoads;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            delete verticalRoads[i][j];
        }
        delete[] verticalRoads[i];
    }
    delete[] verticalRoads;
}

int main()
{
    // testRouteCalculationSimple();
    testRouteCalculationComplex();
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}