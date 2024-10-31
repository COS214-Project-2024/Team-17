#include "../src/Transport/TransportInclude.h"
#include <gtest/gtest.h>

TEST(PointDistance, CheckRoadPointDistance)
{
    RoadComponent *residentialStreet = new ResidentialStreets(0, 0, 10, 0);
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
    EXPECT_EQ(components.size(), 3);
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

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}