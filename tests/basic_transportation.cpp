#include "../src/Transport/TransportInclude.h"
#include <gtest/gtest.h>

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