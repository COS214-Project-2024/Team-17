// Include necessary headers
#include <gtest/gtest.h>
#include "../src/Buildings/Landmark.h"
#include "../src/Buildings/LandCCenter.h"
#include "../src/Buildings/LandPark.h"
#include "../src/Buildings/LandMonument.h"

#include "../src/Citizens/Citizen.h"

#include "../src/Utilities/UtilPowerPlants.h"
#include "../src/Utilities/UtilWaterSupply.h"

class LandmarkTest : public ::testing::Test {
protected:
    Landmark* landmark;

    void SetUp() override {
        // No instantiation as Landmark is abstract
    }

    void TearDown() override {
        delete landmark;
    }
};

TEST_F(LandmarkTest, LandmarkInstantiation) {
    ASSERT_EQ(nullptr, landmark);
}

class LandCCenterTest : public ::testing::Test {
protected:
    LandCCenter* landCCenter;

    void SetUp() override {
        landCCenter = new LandCCenter();
    }

    void TearDown() override {
        delete landCCenter;
    }
};

TEST_F(LandCCenterTest, CreateLandCCenter) {
    ASSERT_NE(landCCenter, nullptr);
}

TEST_F(LandCCenterTest, SetAndGetVisitors) {
    landCCenter->setVisitors(10);
    EXPECT_EQ(landCCenter->getVisitors(), 10);
}

TEST_F(LandCCenterTest, SetAndGetState) {
    landCCenter->setState(true);
    EXPECT_TRUE(landCCenter->getState());

    landCCenter->setState(false);
    EXPECT_FALSE(landCCenter->getState());
}

TEST_F(LandCCenterTest, AddEmployee) {
    Citizen* employee = new Citizen(); 
    EXPECT_TRUE(landCCenter->addEmployee(employee));
    delete employee;
}

TEST_F(LandCCenterTest, RemoveEmployee) {
    Citizen* employee = new Citizen(); 
    EXPECT_TRUE(landCCenter->addEmployee(employee));
    landCCenter->removeEmployee(employee);
    delete employee;
}


TEST_F(LandCCenterTest, AddUtility) {
    UtilityManager* utility = new UtilPowerPlants(); 
    landCCenter->addUtility(utility);

    EXPECT_NO_THROW(landCCenter->notifyUtilities());
    delete utility;
}


TEST_F(LandCCenterTest, DisplayBuildingInfo) {
    testing::internal::CaptureStdout(); 
    landCCenter->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Community center with"), std::string::npos); 
}

class LandParkTest : public ::testing::Test {
protected:
    LandPark* park;

    void SetUp() override {
        park = new LandPark();
    }

    void TearDown() override {
        delete park;
    }
};

TEST_F(LandParkTest, CreateLandPark) {
    ASSERT_NE(park, nullptr);
}

TEST_F(LandParkTest, SetAndGetVisitors) {
    park->setVisitors(20);
    EXPECT_EQ(park->getVisitors(), 20);
}

TEST_F(LandParkTest, AddAndRemoveUtilityLandPark) {
    UtilityManager* utility = new UtilWaterSupply();
    park->addUtility(utility);
    EXPECT_NO_THROW(park->notifyUtilities());
    park->removeUtility(utility);
    EXPECT_NO_THROW(park->notifyUtilities());
    delete utility;
}

TEST_F(LandParkTest, SetAndGetStateLandPark) {
    park->setState(true);
    EXPECT_TRUE(park->getState());
    park->setState(false);
    EXPECT_FALSE(park->getState());
}

TEST_F(LandParkTest, DisplayBuildingInfoLandPark) {
    park->setVisitors(8);
    testing::internal::CaptureStdout();
    park->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Park with 8 visitors"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
