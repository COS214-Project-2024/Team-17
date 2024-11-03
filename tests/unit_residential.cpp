#include <gtest/gtest.h>
#include "../src/Buildings/ResHouse.h"
#include "../src/Buildings/ResTownhouse.h"
#include "../src/Buildings/ResFlat.h"
#include "../src/Buildings/ResEstate.h"

#include "../src/Utilities/UtilPowerPlants.h"

#include "../src/Citizens/Citizen.h"

#include "../src/resources.h"

// Test fixture for ResHouse with resource tracking
class ResHouseTest : public ::testing::Test
{
protected:
    ResHouse *resHouse;

    void SetUp() override
    {
        resHouse = new ResHouse();
    }

    void TearDown() override
    {
        delete resHouse;
    }
};

// Test resource usage and population impact on creation and destruction
TEST_F(ResHouseTest, ResourceUsageOnCreationAndDestruction)
{
    int initialMoney = Resources::getMoney();
    int initialWood = Resources::getWood();
    int initialSteel = Resources::getSteel();
    int initialConcrete = Resources::getConcrete();
    int initialElectricity = Resources::getElectricityUsage();
    int initialWater = Resources::getWaterUsage();
    int initialPopulation = Resources::getMaxPopulation();

    ResHouse *house = new ResHouse();

    EXPECT_EQ(Resources::getMoney(), initialMoney - 2500);
    EXPECT_EQ(Resources::getWood(), initialWood - 15);
    EXPECT_EQ(Resources::getSteel(), initialSteel - 10);
    EXPECT_EQ(Resources::getConcrete(), initialConcrete - 20);
    EXPECT_EQ(Resources::getElectricityUsage(), initialElectricity + 15);
    EXPECT_EQ(Resources::getWaterUsage(), initialWater + 15);
    EXPECT_EQ(Resources::getMaxPopulation(), initialPopulation + 20);

    delete house;

    EXPECT_EQ(Resources::getElectricityUsage(), initialElectricity);
    EXPECT_EQ(Resources::getWaterUsage(), initialWater);
    EXPECT_EQ(Resources::getMaxPopulation(), initialPopulation);
}

// Test moving in residents while respecting capacity limits
TEST_F(ResHouseTest, MoveInResidentWithinCapacity)
{
    resHouse->setCapacity(2);
    Citizen *resident1 = new Citizen();
    Citizen *resident2 = new Citizen();

    EXPECT_TRUE(resHouse->moveIn(resident1));
    EXPECT_TRUE(resHouse->moveIn(resident2));

    // Exceeding capacity
    Citizen *resident3 = new Citizen();
    EXPECT_FALSE(resHouse->moveIn(resident3));

    delete resident1;
    delete resident2;
    delete resident3;
}

// // Test moving out residents and ensuring they are removed correctly
// TEST_F(ResHouseTest, MoveOutResident) {
//     Citizen* resident = new Citizen();
//     resHouse->setCapacity(1);
//     resHouse->moveIn(resident);

//     resHouse->moveOut(resident);

//     // Check that the house no longer contains the resident
//     EXPECT_TRUE(resHouse->moveIn(resident)); // Should succeed since resident was removed

//     delete resident;
// }

// // Test the operational state change and utility call
// TEST_F(ResHouseTest, StateChangeTriggersUtilityCall) {
//     // Initially, the house should be non-operational (false)
//     resHouse->setState(false);
//     EXPECT_FALSE(resHouse->getState());

//     // Change state to operational
//     resHouse->setState(true);
//     EXPECT_TRUE(resHouse->getState());

//     // Test that setting the same state doesn't trigger additional changes
//     resHouse->setState(true); // No change should happen, expect no errors
// }

// // Test to verify building type
// TEST_F(ResHouseTest, BuildingTypeIsCorrect) {
//     EXPECT_EQ(resHouse->getBuildingType(), "Residential House");
// }

// // Test if displayBuildingInfo outputs the correct format
// TEST_F(ResHouseTest, DisplayBuildingInfoOutput) {
//     resHouse->setCapacity(5);
//     testing::internal::CaptureStdout(); // Capture the output
//     resHouse->displayBuildingInfo();
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("House for 5 people"), std::string::npos); // Check expected text in output
// }

// // Test fixture for ResTownhouse
// class ResTownhouseTest : public ::testing::Test {
// protected:
//     ResTownhouse* resTownhouse;

//     void SetUp() override {
//         resTownhouse = new ResTownhouse();
//     }

//     void TearDown() override {
//         delete resTownhouse;
//     }
// };

// // Test ResTownhouse creation
// TEST_F(ResTownhouseTest, CreateResTownhouse) {
//     ASSERT_NE(resTownhouse, nullptr);
// }

// // Test ResTownhouse capacity
// TEST_F(ResTownhouseTest, SetAndGetCapacity) {
//     resTownhouse->setCapacity(3);
//     EXPECT_EQ(resTownhouse->getCapacity(), 3);
// }

// // Test moving in a resident
// TEST_F(ResTownhouseTest, MoveInResident) {
//     Citizen* resident = new Citizen(); // Assuming Citizen has a default constructor
//     resTownhouse->setCapacity(2);
//     EXPECT_TRUE(resTownhouse->moveIn(resident));
//     EXPECT_EQ(resTownhouse->getCapacity(), 2);
//     delete resident;
// }

// // Test moving out a resident
// TEST_F(ResTownhouseTest, MoveOutResident) {
//     Citizen* resident = new Citizen();
//     resTownhouse->setCapacity(1);
//     resTownhouse->moveIn(resident);
//     resTownhouse->moveOut(resident);
//     // Check if the resident is no longer in the townhouse
//     EXPECT_TRUE(resTownhouse->moveIn(resident));
//     delete resident;
// }

// // Test utility connection
// TEST_F(ResTownhouseTest, AddUtility) {
//     UtilityManager* utility = new UtilPowerPlants(); // Use a concrete utility class
//     resTownhouse->addUtility(utility);
//     EXPECT_NO_THROW(resTownhouse->notifyUtilities());
//     delete utility;
// }

// // Test state change and observer notification
// TEST_F(ResTownhouseTest, SetAndGetState) {
//     resTownhouse->setState(true);
//     EXPECT_TRUE(resTownhouse->getState());
//     resTownhouse->setState(false);
//     EXPECT_FALSE(resTownhouse->getState());
// }

// // Test that building info displays correctly
// TEST_F(ResTownhouseTest, DisplayBuildingInfo) {
//     resTownhouse->setCapacity(4);
//     testing::internal::CaptureStdout(); // Capture the output
//     resTownhouse->displayBuildingInfo();
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("Townhouse for 4 people"), std::string::npos); // Check expected string in output
// }

// // Test building type retrieval
// TEST_F(ResTownhouseTest, GetBuildingType) {
//     EXPECT_EQ(resTownhouse->getBuildingType(), "Residential Townhouse");
// }

// // Test fixture for ResFlat
// class ResFlatTest : public ::testing::Test {
// protected:
//     ResFlat* resFlat;

//     void SetUp() override {
//         resFlat = new ResFlat();
//     }

//     void TearDown() override {
//         delete resFlat;
//     }
// };

// // Test ResFlat creation
// TEST_F(ResFlatTest, CreateResFlat) {
//     ASSERT_NE(resFlat, nullptr);
// }

// // Test ResFlat capacity
// TEST_F(ResFlatTest, SetAndGetCapacity) {
//     resFlat->setCapacity(3);
//     EXPECT_EQ(resFlat->getCapacity(), 3);
// }

// // Test moving in a resident
// TEST_F(ResFlatTest, MoveInResident) {
//     Citizen* resident = new Citizen();
//     resFlat->setCapacity(2);
//     EXPECT_TRUE(resFlat->moveIn(resident));
//     EXPECT_EQ(resFlat->getCapacity(), 2);
//     delete resident;
// }

// // Test moving out a resident
// TEST_F(ResFlatTest, MoveOutResident) {
//     Citizen* resident = new Citizen();
//     resFlat->setCapacity(1);
//     resFlat->moveIn(resident);
//     resFlat->moveOut(resident);
//     // Check if the resident is no longer in the flat
//     EXPECT_TRUE(resFlat->moveIn(resident));
//     delete resident;
// }

// // Test utility connection
// TEST_F(ResFlatTest, AddUtility) {
//     UtilityManager* utility = new UtilPowerPlants();
//     resFlat->addUtility(utility);
//     EXPECT_NO_THROW(resFlat->notifyUtilities());
//     delete utility;
// }

// // Test state change and observer notification
// TEST_F(ResFlatTest, SetAndGetState) {
//     resFlat->setState(true);
//     EXPECT_TRUE(resFlat->getState());
//     resFlat->setState(false);
//     EXPECT_FALSE(resFlat->getState());
// }

// // Test that building info displays correctly
// TEST_F(ResFlatTest, DisplayBuildingInfo) {
//     resFlat->setCapacity(3);
//     testing::internal::CaptureStdout(); // Capture the output
//     resFlat->displayBuildingInfo();
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("Flat for 3 people"), std::string::npos); // Check expected string in output
// }

// // Test building type retrieval
// TEST_F(ResFlatTest, GetBuildingType) {
//     EXPECT_EQ(resFlat->getBuildingType(), "Residential Flat");
// }

// // Test fixture for ResEstate
// class ResEstateTest : public ::testing::Test {
// protected:
//     ResEstate* resEstate;

//     void SetUp() override {
//         resEstate = new ResEstate();
//     }

//     void TearDown() override {
//         delete resEstate;
//     }
// };

// // Test ResEstate creation
// TEST_F(ResEstateTest, CreateResEstate) {
//     ASSERT_NE(resEstate, nullptr);
// }

// // Test ResEstate capacity
// TEST_F(ResEstateTest, SetAndGetCapacity) {
//     resEstate->setCapacity(50);
//     EXPECT_EQ(resEstate->getCapacity(), 50);
// }

// // Test moving in a resident
// TEST_F(ResEstateTest, MoveInResident) {
//     Citizen* resident = new Citizen();
//     resEstate->setCapacity(10);
//     EXPECT_TRUE(resEstate->moveIn(resident));
//     delete resident;
// }

// // Test moving out a resident
// TEST_F(ResEstateTest, MoveOutResident) {
//     Citizen* resident = new Citizen();
//     resEstate->setCapacity(10);
//     resEstate->moveIn(resident);
//     resEstate->moveOut(resident);
//     EXPECT_TRUE(resEstate->moveIn(resident));  // Check if the resident can move in again after moving out
//     delete resident;
// }

// // Test utility connection
// TEST_F(ResEstateTest, AddUtility) {
//     UtilityManager* utility = new UtilPowerPlants();
//     resEstate->addUtility(utility);
//     EXPECT_NO_THROW(resEstate->notifyUtilities());
//     delete utility;
// }

// // Test state change and observer notification
// TEST_F(ResEstateTest, SetAndGetState) {
//     resEstate->setState(true);
//     EXPECT_TRUE(resEstate->getState());
//     resEstate->setState(false);
//     EXPECT_FALSE(resEstate->getState());
// }

// // Test displayBuildingInfo
// TEST_F(ResEstateTest, DisplayBuildingInfo) {
//     resEstate->setCapacity(50);
//     testing::internal::CaptureStdout();
//     resEstate->displayBuildingInfo();
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("Estate for 50 people"), std::string::npos);
// }

// // Test building type retrieval
// TEST_F(ResEstateTest, GetBuildingType) {
//     EXPECT_EQ(resEstate->getBuildingType(), "Residential Estate");
// }

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}