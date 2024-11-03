#include <gtest/gtest.h>
#include <iostream>
#include "../src/Utilities/UtilPowerPlants.h"
#include "../src/Utilities/UtilSewageSyst.h"
#include "../src/Utilities/UtilWasteMan.h"
#include "../src/Utilities/UtilWaterSupply.h"
#include "../src/Buildings/ComMall.h" // Assuming a basic Building class with getState() method

// Test cases for UtilPowerPlants
TEST(UtilPowerPlantsTest, StartsAndShutsDownCorrectly)
{
    UtilPowerPlants powerPlant;
    EXPECT_FALSE(powerPlant.isOperational()); // Initially should be non-operational
    powerPlant.startUtility();
    EXPECT_TRUE(powerPlant.isOperational()); // After starting, should be operational
    powerPlant.shutDown();
    EXPECT_FALSE(powerPlant.isOperational()); // After shutdown, should be non-operational
}

TEST(UtilPowerPlantsTest, TypeIsCorrect)
{
    UtilPowerPlants powerPlant;
    EXPECT_EQ(powerPlant.getType(), "Power Plant");
}

// Test cases for UtilSewageSyst
TEST(UtilSewageSystTest, StartsAndShutsDownCorrectly)
{
    UtilSewageSyst sewageSystem;
    EXPECT_FALSE(sewageSystem.isOperational()); // Initially should be non-operational
    sewageSystem.startUtility();
    EXPECT_TRUE(sewageSystem.isOperational()); // After starting, should be operational
    sewageSystem.shutDown();
    EXPECT_FALSE(sewageSystem.isOperational()); // After shutdown, should be non-operational
}

TEST(UtilSewageSystTest, TypeIsCorrect)
{
    UtilSewageSyst sewageSystem;
    EXPECT_EQ(sewageSystem.getType(), "Sewage System");
}

// Test cases for UtilWasteMan
TEST(UtilWasteManTest, StartsAndShutsDownCorrectly)
{
    UtilWasteMan wasteManagement;
    EXPECT_FALSE(wasteManagement.isOperational()); // Initially should be non-operational
    wasteManagement.startUtility();
    EXPECT_TRUE(wasteManagement.isOperational()); // After starting, should be operational
    wasteManagement.shutDown();
    EXPECT_FALSE(wasteManagement.isOperational()); // After shutdown, should be non-operational
}

TEST(UtilWasteManTest, TypeIsCorrect)
{
    UtilWasteMan wasteManagement;
    EXPECT_EQ(wasteManagement.getType(), "Waste Dump");
}

// Test cases for UtilWaterSupply
TEST(UtilWaterSupplyTest, StartsAndShutsDownCorrectly)
{
    UtilWaterSupply waterSupply;
    EXPECT_FALSE(waterSupply.isOperational()); // Initially should be non-operational
    waterSupply.startUtility();
    EXPECT_TRUE(waterSupply.isOperational()); // After starting, should be operational
    waterSupply.shutDown();
    EXPECT_FALSE(waterSupply.isOperational()); // After shutdown, should be non-operational
}

TEST(UtilWaterSupplyTest, TypeIsCorrect)
{
    UtilWaterSupply waterSupply;
    EXPECT_EQ(waterSupply.getType(), "Water Supply");
}

// General test case for utility updates based on Building state
TEST(UtilityTest, UpdatesAccordingToBuildingState)
{
    ComMall building;
    UtilPowerPlants powerPlant;
    UtilSewageSyst sewageSystem;
    UtilWasteMan wasteManagement;
    UtilWaterSupply waterSupply;

    // Assuming Building starts off non-operational
    EXPECT_FALSE(building.getState());

    // Update utilities and check if they start when building is non-operational
    powerPlant.update(&building);
    sewageSystem.update(&building);
    wasteManagement.update(&building);
    waterSupply.update(&building);

    EXPECT_TRUE(powerPlant.isOperational());
    EXPECT_TRUE(sewageSystem.isOperational());
    EXPECT_TRUE(wasteManagement.isOperational());
    EXPECT_TRUE(waterSupply.isOperational());

    // Change Building state to operational and update utilities again
    building.setState(true); // Assuming setState exists in Building
    powerPlant.update(&building);
    sewageSystem.update(&building);
    wasteManagement.update(&building);
    waterSupply.update(&building);

    EXPECT_TRUE(powerPlant.isOperational());
    EXPECT_TRUE(sewageSystem.isOperational());
    EXPECT_TRUE(wasteManagement.isOperational());
    EXPECT_TRUE(waterSupply.isOperational());
}

// Main function for running all tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
