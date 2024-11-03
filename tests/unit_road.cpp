// This will test roads
#include <gtest/gtest.h>
#include <cmath>
#include <cassert>
#include <iostream>
#include "../src/Transport/RoadComponentTypes/Highways.h"
#include "../src/Transport/RoadComponentTypes/RoadsComposite.h"
#include "../src/Transport/RoadComponent.h"
#include "../src/Transport/RoadComponentTypes/MainRoads.h"

#include "../src/Citizens/Citizen.h"

class HighwaysTest : public ::testing::Test {
protected:
    Highways *highway;

    void SetUp() override {
        highway = new Highways(0, 0, 10, 10);
    }

    void TearDown() override {
        delete highway;
    }
};

TEST_F(HighwaysTest, GetDistance) {
    // Check if distance is calculated correctly
    float expectedDistance = std::sqrt(200); // sqrt((10-0)^2 + (10-0)^2)
    EXPECT_NEAR(highway->getDistance(), expectedDistance, 0.001);
}

TEST_F(HighwaysTest, AddUser) {
    // Test adding a user to the highway
    Citizen user;
    bool success = highway->addUser(&user);
    EXPECT_TRUE(success);
    EXPECT_EQ(highway->getUsers().size(), 1);
}

class RoadsCompositeTest : public ::testing::Test {
protected:
    RoadsComposite *roadComposite;

    void SetUp() override {
        roadComposite = new RoadsComposite(0, 0, 200, 200, "main");
    }

    void TearDown() override {
        delete roadComposite;
    }
};

TEST_F(RoadsCompositeTest, GetDistance) {
    // Check if composite distance is calculated as expected
    float expectedDistance = std::sqrt(200 * 200 + 200 * 200);
    EXPECT_NEAR(roadComposite->getDistance(), expectedDistance, 0.001);
}

// Helper function to compare floating-point values
bool areEqual(float a, float b, float epsilon = 0.0001f) {
    return std::fabs(a - b) < epsilon;
}

class MainRoadsTest : public ::testing::Test {
protected:
    MainRoads *road;

    void SetUp() override {
        road = new MainRoads(0, 0, 4, 4);
    }

    void TearDown() override {
        delete road;
    }
};

TEST_F(MainRoadsTest, CalculateDistance_SamePoint) {
    float distance = road->calculateDistance(1, 1);
    float expectedDistance = 0.0f;  // Closest point on the segment is itself
    EXPECT_TRUE(areEqual(distance, expectedDistance));
}

TEST_F(MainRoadsTest, CalculateDistance_OnLine) {
    float distance = road->calculateDistance(3, 3);
    float expectedDistance = 0.0f;  // Also on the line
    EXPECT_TRUE(areEqual(distance, expectedDistance));
}

TEST_F(MainRoadsTest, CalculateDistance_OffLine) {
    float distance = road->calculateDistance(4, 0);
    float expectedDistance = std::sqrt(8.0f);  // Distance to closest point on line
    EXPECT_TRUE(areEqual(distance, expectedDistance));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
