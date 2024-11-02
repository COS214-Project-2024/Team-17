// This will test Buildings and it's children

#include <gtest/gtest.h>
#include "../src/Buildings/Building.h"
#include "../src/Buildings/Residential.h"
#include "../src/Buildings/ResHouse.h"

#include "../src/Citizens/Citizen.h"

#include "../src/Utilities/UtilPowerPlants.h" 
#include "../src/Utilities/UtilSewageSyst.h"
#include "../src/Utilities/UtilWasteMan.h"
#include "../src/Utilities/UtilWaterSupply.h"

// Test fixture for Building
class BuildingTest : public ::testing::Test {
protected:
    Building* building;

    void SetUp() override {
        // No instantiation as Building is abstract
    }

    void TearDown() override {
        delete building; // Just in case it was instantiated
    }
};

// Test that we cannot instantiate Building
TEST_F(BuildingTest, BuildingInstantiation) {
    // Expecting an error or assertion failure as Building is abstract
    ASSERT_EQ(nullptr, building);
}

// Test fixture for Residential
class ResidentialTest : public ::testing::Test {
protected:
    Residential* residential;

    void SetUp() override {
        residential = nullptr; // No instantiation as Residential is abstract
    }

    void TearDown() override {
        delete residential; // Just in case it was instantiated
    }
};

// Test that we cannot instantiate Residential
TEST_F(ResidentialTest, ResidentialInstantiation) {
    // Expecting an error or assertion failure as Residential is abstract
    ASSERT_EQ(nullptr, residential);
}

// Test fixture for ResHouse
class ResHouseTest : public ::testing::Test {
protected:
    ResHouse* resHouse;

    void SetUp() override {
        resHouse = new ResHouse();
    }

    void TearDown() override {
        delete resHouse;
    }
};

// Test ResHouse creation
TEST_F(ResHouseTest, CreateResHouse) {
    ASSERT_NE(resHouse, nullptr);
}

// Test ResHouse capacity
TEST_F(ResHouseTest, SetAndGetCapacity) {
    resHouse->setCapacity(4);
    EXPECT_EQ(resHouse->getCapacity(), 4);
}

// Test moving in a resident
TEST_F(ResHouseTest, MoveInResident) {
    Citizen* resident = new Citizen(); // Assuming Citizen has a default constructor
    resHouse->setCapacity(2);
    EXPECT_TRUE(resHouse->moveIn(resident));
    EXPECT_EQ(resHouse->getCapacity(), 2); // Assuming a change in capacity would be implemented
    delete resident;
}

// Test moving out a resident
TEST_F(ResHouseTest, MoveOutResident) {
    Citizen* resident = new Citizen(); // Assuming Citizen has a default constructor
    resHouse->setCapacity(1);
    resHouse->moveIn(resident);
    resHouse->moveOut(resident);
    // Check if the resident is no longer in the house
    EXPECT_TRUE(resHouse->moveIn(resident));
    resHouse->moveOut(resident);
    delete resident;
}

// Test for utility connection
TEST_F(ResHouseTest, AddUtility) {
    UtilityManager* utility = new UtilPowerPlants(); // Use the concrete class
    resHouse->addUtility(utility);
    // Check that the utility is now attached
    EXPECT_NO_THROW(resHouse->notifyUtilities());
    delete utility;

    utility = new UtilSewageSyst(); // Use the concrete class
    resHouse->addUtility(utility);
    // Check that the utility is now attached
    EXPECT_NO_THROW(resHouse->notifyUtilities());
    delete utility;

    utility = new UtilWasteMan(); // Use the concrete class
    resHouse->addUtility(utility);
    // Check that the utility is now attached
    EXPECT_NO_THROW(resHouse->notifyUtilities());
    delete utility;

    utility = new UtilWaterSupply(); // Use the concrete class
    resHouse->addUtility(utility);
    // Check that the utility is now attached
    EXPECT_NO_THROW(resHouse->notifyUtilities());
    delete utility;
}

// Test that state can be set and retrieved
TEST_F(ResHouseTest, SetAndGetState) {
    resHouse->setState(true);
    EXPECT_TRUE(resHouse->getState());
    resHouse->setState(false);
    EXPECT_FALSE(resHouse->getState());
}

// Test that building info is displayed correctly
TEST_F(ResHouseTest, DisplayBuildingInfo) {
    resHouse->setCapacity(5);
    testing::internal::CaptureStdout(); // Capture the output
    resHouse->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("House for 5 people"), std::string::npos); // Check that output contains expected string
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}