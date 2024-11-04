#include <gtest/gtest.h>
#include <iostream>
#include "../src/Utilities/UtilPowerPlants.h"
#include "../src/Utilities/UtilSewageSyst.h"
#include "../src/Utilities/UtilWasteMan.h"
#include "../src/Utilities/UtilWaterSupply.h"
#include "../src/Buildings/ComMall.h"

TEST(UtilPowerPlantsTest, StartsAndShutsDownCorrectly) {
    UtilPowerPlants powerPlant;
    EXPECT_FALSE(powerPlant.isOperational()); 
    powerPlant.startUtility();
    EXPECT_TRUE(powerPlant.isOperational());
    powerPlant.shutDown();
    EXPECT_FALSE(powerPlant.isOperational());
}

TEST(UtilPowerPlantsTest, TypeIsCorrect) {
    UtilPowerPlants powerPlant;
    EXPECT_EQ(powerPlant.getType(), "Power Plant");
}

TEST(UtilSewageSystTest, StartsAndShutsDownCorrectly) {
    UtilSewageSyst sewageSystem;
    EXPECT_FALSE(sewageSystem.isOperational());
    sewageSystem.startUtility();
    EXPECT_TRUE(sewageSystem.isOperational());
    sewageSystem.shutDown();
    EXPECT_FALSE(sewageSystem.isOperational());
}

TEST(UtilSewageSystTest, TypeIsCorrect) {
    UtilSewageSyst sewageSystem;
    EXPECT_EQ(sewageSystem.getType(), "Sewage System");
}

TEST(UtilWasteManTest, StartsAndShutsDownCorrectly) {
    UtilWasteMan wasteManagement;
    EXPECT_FALSE(wasteManagement.isOperational()); 
    wasteManagement.startUtility();
    EXPECT_TRUE(wasteManagement.isOperational());
    wasteManagement.shutDown();
    EXPECT_FALSE(wasteManagement.isOperational());
}

TEST(UtilWasteManTest, TypeIsCorrect) {
    UtilWasteMan wasteManagement;
    EXPECT_EQ(wasteManagement.getType(), "Waste Dump");
}

TEST(UtilWaterSupplyTest, StartsAndShutsDownCorrectly) {
    UtilWaterSupply waterSupply;
    EXPECT_FALSE(waterSupply.isOperational()); 
    waterSupply.startUtility();
    EXPECT_TRUE(waterSupply.isOperational());
    waterSupply.shutDown();
    EXPECT_FALSE(waterSupply.isOperational()); 
}

TEST(UtilWaterSupplyTest, TypeIsCorrect) {
    UtilWaterSupply waterSupply;
    EXPECT_EQ(waterSupply.getType(), "Water Supply");
}

// General test case for utility updates based on Building state
TEST(UtilityTest, UpdatesAccordingToBuildingState) {
    ComMall building;
    UtilPowerPlants powerPlant;
    UtilSewageSyst sewageSystem;
    UtilWasteMan wasteManagement;
    UtilWaterSupply waterSupply;

    EXPECT_FALSE(building.getState());

    powerPlant.update(&building);
    sewageSystem.update(&building);
    wasteManagement.update(&building);
    waterSupply.update(&building);

    EXPECT_TRUE(powerPlant.isOperational());
    EXPECT_TRUE(sewageSystem.isOperational());
    EXPECT_TRUE(wasteManagement.isOperational());
    EXPECT_TRUE(waterSupply.isOperational());

    building.setState(true);
    powerPlant.update(&building);
    sewageSystem.update(&building);
    wasteManagement.update(&building);
    waterSupply.update(&building);

    EXPECT_TRUE(powerPlant.isOperational());
    EXPECT_TRUE(sewageSystem.isOperational());
    EXPECT_TRUE(wasteManagement.isOperational());
    EXPECT_TRUE(waterSupply.isOperational());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
