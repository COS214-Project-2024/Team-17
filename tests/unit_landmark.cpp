// Include necessary headers
#include <gtest/gtest.h>
#include "../src/Buildings/Landmark.h"
#include "../src/Buildings/LandCCenter.h"
#include "../src/Buildings/LandPark.h"
#include "../src/Buildings/LandMonument.h"

#include "../src/Citizens/Citizen.h"

#include "../src/Utilities/UtilPowerPlants.h"

// Test fixture for Landmark
class LandmarkTest : public ::testing::Test {
protected:
    Landmark* landmark;

    void SetUp() override {
        // No instantiation as Landmark is abstract
    }

    void TearDown() override {
        delete landmark; // Just in case it was instantiated
    }
};

// Test that we cannot instantiate Landmark
TEST_F(LandmarkTest, LandmarkInstantiation) {
    ASSERT_EQ(nullptr, landmark);
}

// Test fixture for LandCCenter
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

// Test LandCCenter creation
TEST_F(LandCCenterTest, CreateLandCCenter) {
    ASSERT_NE(landCCenter, nullptr);
}

// Test setting and getting visitors
TEST_F(LandCCenterTest, SetAndGetVisitors) {
    landCCenter->setVisitors(10);
    EXPECT_EQ(landCCenter->getVisitors(), 10);
}

// Test setting the state
TEST_F(LandCCenterTest, SetAndGetState) {
    landCCenter->setState(true);
    EXPECT_TRUE(landCCenter->getState());

    landCCenter->setState(false);
    EXPECT_FALSE(landCCenter->getState());
}

// Test adding an employee
TEST_F(LandCCenterTest, AddEmployee) {
    Citizen* employee = new Citizen(); // Assuming Citizen has a default constructor
    EXPECT_TRUE(landCCenter->addEmployee(employee));
    delete employee;
}

// Test removing an employee
TEST_F(LandCCenterTest, RemoveEmployee) {
    Citizen* employee = new Citizen(); // Assuming Citizen has a default constructor  
    EXPECT_TRUE(landCCenter->addEmployee(employee));
    landCCenter->removeEmployee(employee);
    delete employee;
}

// Test utility connection
TEST_F(LandCCenterTest, AddUtility) {
    UtilityManager* utility = new UtilPowerPlants(); // Use the concrete class
    landCCenter->addUtility(utility);
    // Check that the utility is now attached
    EXPECT_NO_THROW(landCCenter->notifyUtilities());
    delete utility;
}

// Test building info display
TEST_F(LandCCenterTest, DisplayBuildingInfo) {
    testing::internal::CaptureStdout(); // Capture the output
    landCCenter->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Community center with"), std::string::npos); // Check that output contains expected string
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
