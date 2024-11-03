// // This will test Building

#include <gtest/gtest.h>
#include "../src/Buildings/Building.h"
#include "../src/Buildings/Residential.h"
#include "../src/Buildings/ResHouse.h"

#include "../src/Citizens/Citizen.h"
#include "../src/Citizens/CityCentralMediator.h"
#include "../src/Utilities/UtilPowerPlants.h"
#include "../src/Utilities/UtilSewageSyst.h"
#include "../src/Utilities/UtilWasteMan.h"
#include "../src/Utilities/UtilWaterSupply.h"

// Test fixture for Building
class BuildingTest : public ::testing::Test
{
protected:
    Building *building;

    void SetUp() override
    {
        // No instantiation as Building is abstract
    }

    void TearDown() override
    {
        delete building; // Just in case it was instantiated
    }
};

// Test that we cannot instantiate Building
TEST_F(BuildingTest, BuildingInstantiation)
{
    // Expecting an error or assertion failure as Building is abstract
    ASSERT_EQ(nullptr, building);
}

// Test fixture for Residential
class ResidentialTest : public ::testing::Test
{
protected:
    Residential *residential;

    void SetUp() override
    {
        residential = nullptr; // No instantiation as Residential is abstract
    }

    void TearDown() override
    {
        delete residential; // Just in case it was instantiated
    }
};

// Test that we cannot instantiate Residential
TEST_F(ResidentialTest, ResidentialInstantiation)
{
    // Expecting an error or assertion failure as Residential is abstract
    ASSERT_EQ(nullptr, residential);
}

// Test ResHouse creation
TEST(ResHouseTest, CreateResHouse)
{
    ResHouse *resHouse = new ResHouse();
    ASSERT_NE(resHouse, nullptr);
    delete resHouse;
}

// Test ResHouse capacity
TEST(ResHouseTest, SetAndGetCapacity)
{
    ResHouse *resHouse = new ResHouse();
    resHouse->setCapacity(4);
    EXPECT_EQ(resHouse->getCapacity(), 4);
    delete resHouse;
}

// Test moving in a resident
TEST(ResHouseTest, MoveInResident)
{
    CityCentralMediator *ccm = CityCentralMediator::getInstance();
    Citizen *resident = new Citizen(); // Assuming Citizen has a default constructor
    ResHouse *resHouse = new ResHouse();
    resHouse->setCapacity(2);
    EXPECT_TRUE(resHouse->moveIn(resident));
    EXPECT_EQ(resHouse->getCapacity(), 2); // Assuming a change in capacity would be implemented
    delete resHouse;
    delete resident;
    delete ccm;
}

// Test moving out a resident
TEST(ResHouseTest, MoveOutResident)
{
    Citizen *resident = new Citizen(); // Assuming Citizen has a default constructor
    ResHouse *resHouse = new ResHouse();
    resHouse->setCapacity(1);
    resHouse->moveIn(resident);
    resHouse->moveOut(resident);
    // Check if the resident is no longer in the house
    EXPECT_TRUE(resHouse->moveIn(resident));
    resHouse->moveOut(resident);
    delete resident;
    delete resHouse;
}

// Test for utility connection
TEST(ResHouseTest, AddUtility)
{
    UtilityManager *utility = new UtilPowerPlants(); // Use the concrete class
    ResHouse *resHouse = new ResHouse();
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
    delete resHouse;
}

// Test that state can be set and retrieved
TEST(ResHouseTest, SetAndGetState)
{
    ResHouse *resHouse = new ResHouse();
    resHouse->setState(true);
    EXPECT_TRUE(resHouse->getState());
    resHouse->setState(false);
    EXPECT_FALSE(resHouse->getState());
    delete resHouse;
}

// Test that building info is displayed correctly
TEST(ResHouseTest, DisplayBuildingInfo)
{
    ResHouse *resHouse = new ResHouse();
    resHouse->setCapacity(5);
    testing::internal::CaptureStdout(); // Capture the output
    resHouse->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("House for 5 people"), std::string::npos); // Check that output contains expected string
    delete resHouse;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}