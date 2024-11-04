#include <gtest/gtest.h>
#include "../src/Buildings/ResHouse.h"
#include "../src/Buildings/ResTownhouse.h"
#include "../src/Buildings/ResFlat.h"
#include "../src/Buildings/ResEstate.h"

#include "../src/Utilities/UtilPowerPlants.h"

#include "../src/Citizens/Citizen.h"

#include "../src/resources.h"

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

TEST_F(ResHouseTest, ResourceUsageOnCreationAndDestruction) {
    int initialMoney = Resources::getMoney();
    int initialWood = Resources::getWood();
    int initialSteel = Resources::getSteel();
    int initialConcrete = Resources::getConcrete();
    int initialElectricity = Resources::getElectricityUsage();
    int initialWater = Resources::getWaterUsage();
    int initialPopulation = Resources::getMaxPopulation();

    ResHouse* house = new ResHouse();

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

TEST_F(ResHouseTest, MoveInResidentWithinCapacity) {
    resHouse->setCapacity(20);
    Citizen* resident1 = new Citizen();
    Citizen* resident2 = new Citizen();

    EXPECT_TRUE(resHouse->moveIn(resident1));
    EXPECT_TRUE(resHouse->moveIn(resident2));

    Citizen* resident3 = new Citizen();
    EXPECT_TRUE(resHouse->moveIn(resident3));

    delete resident1;
    delete resident2;
    delete resident3;
}

TEST_F(ResHouseTest, MoveOutResident) {
    Citizen* resident = new Citizen();
    resHouse->setCapacity(1);
    resHouse->moveIn(resident);

    resHouse->moveOut(resident);

    EXPECT_TRUE(resHouse->moveIn(resident));

    delete resident;
}

TEST_F(ResHouseTest, StateChangeTriggersUtilityCall) {
    resHouse->setState(false);
    EXPECT_FALSE(resHouse->getState());

    resHouse->setState(true);
    EXPECT_TRUE(resHouse->getState());

    resHouse->setState(true);

}

TEST_F(ResHouseTest, BuildingTypeIsCorrect) {
    EXPECT_EQ(resHouse->getBuildingType(), "Residential House");
}


TEST_F(ResHouseTest, DisplayBuildingInfoOutput) {
    resHouse->setCapacity(20);
    testing::internal::CaptureStdout();
    resHouse->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("House for 20 people"), std::string::npos); // Check expected text in output
}


class ResTownhouseTest : public ::testing::Test {
protected:
    ResTownhouse* resTownhouse;

    void SetUp() override {
        resTownhouse = new ResTownhouse();
    }

    void TearDown() override {
        delete resTownhouse;
    }
};


TEST_F(ResTownhouseTest, CreateResTownhouse) {
    ASSERT_NE(resTownhouse, nullptr);
}


TEST_F(ResTownhouseTest, SetAndGetCapacity) {
    resTownhouse->setCapacity(10);
    EXPECT_EQ(resTownhouse->getCapacity(), 10);
}


TEST_F(ResTownhouseTest, MoveInResident) {
    Citizen* resident = new Citizen();
    resTownhouse->setCapacity(2);
    EXPECT_TRUE(resTownhouse->moveIn(resident));
    EXPECT_EQ(resTownhouse->getCapacity(), 10);
    delete resident;
}

TEST_F(ResTownhouseTest, MoveOutResident) {
    Citizen* resident = new Citizen();
    resTownhouse->setCapacity(1);
    resTownhouse->moveIn(resident);
    resTownhouse->moveOut(resident);
    
    EXPECT_TRUE(resTownhouse->moveIn(resident));
    delete resident;
}


TEST_F(ResTownhouseTest, AddUtility) {
    UtilityManager* utility = new UtilPowerPlants(); // Use a concrete utility class
    resTownhouse->addUtility(utility);
    EXPECT_NO_THROW(resTownhouse->notifyUtilities());
    delete utility;
}

TEST_F(ResTownhouseTest, SetAndGetState) {
    resTownhouse->setState(true);
    EXPECT_TRUE(resTownhouse->getState());
    resTownhouse->setState(false);
    EXPECT_FALSE(resTownhouse->getState());
}

TEST_F(ResTownhouseTest, DisplayBuildingInfo) {
    resTownhouse->setCapacity(4);
    testing::internal::CaptureStdout(); 
    resTownhouse->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Townhouse for 10 people"), std::string::npos); // Check expected string in output
}

TEST_F(ResTownhouseTest, GetBuildingType) {
    EXPECT_EQ(resTownhouse->getBuildingType(), "Residential Townhouse");
}

class ResFlatTest : public ::testing::Test {
protected:
    ResFlat* resFlat;

    void SetUp() override {
        resFlat = new ResFlat();
    }

    void TearDown() override {
        delete resFlat;
    }
};

TEST_F(ResFlatTest, CreateResFlat) {
    ASSERT_NE(resFlat, nullptr);
}

TEST_F(ResFlatTest, SetAndGetCapacity) {
    resFlat->setCapacity(3);
    EXPECT_EQ(resFlat->getCapacity(), 5);
}

TEST_F(ResFlatTest, MoveInResident) {
    Citizen* resident = new Citizen();
    resFlat->setCapacity(2);
    EXPECT_TRUE(resFlat->moveIn(resident));
    EXPECT_EQ(resFlat->getCapacity(), 5);
    delete resident;
}

TEST_F(ResFlatTest, MoveOutResident) {
    Citizen* resident = new Citizen();
    resFlat->setCapacity(1);
    resFlat->moveIn(resident);
    resFlat->moveOut(resident);
    
    EXPECT_TRUE(resFlat->moveIn(resident));
    delete resident;
}

TEST_F(ResFlatTest, AddUtility) {
    UtilityManager* utility = new UtilPowerPlants();
    resFlat->addUtility(utility);
    EXPECT_NO_THROW(resFlat->notifyUtilities());
    delete utility;
}

TEST_F(ResFlatTest, SetAndGetState) {
    resFlat->setState(true);
    EXPECT_TRUE(resFlat->getState());
    resFlat->setState(false);
    EXPECT_FALSE(resFlat->getState());
}

TEST_F(ResFlatTest, DisplayBuildingInfo) {
    resFlat->setCapacity(3);
    testing::internal::CaptureStdout(); // Capture the output
    resFlat->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Flat for 5 people"), std::string::npos); // Check expected string in output
}

TEST_F(ResFlatTest, GetBuildingType) {
    EXPECT_EQ(resFlat->getBuildingType(), "Residential Flat");
}

class ResEstateTest : public ::testing::Test {
protected:
    ResEstate* resEstate;

    void SetUp() override {
        resEstate = new ResEstate();
    }

    void TearDown() override {
        delete resEstate;
    }
};

TEST_F(ResEstateTest, CreateResEstate) {
    ASSERT_NE(resEstate, nullptr);
}

TEST_F(ResEstateTest, SetAndGetCapacity) {
    resEstate->setCapacity(50);
    EXPECT_EQ(resEstate->getCapacity(), 50);
}

TEST_F(ResEstateTest, MoveInResident) {
    Citizen* resident = new Citizen();
    resEstate->setCapacity(10);
    EXPECT_TRUE(resEstate->moveIn(resident));
    delete resident;
}

TEST_F(ResEstateTest, MoveOutResident) {
    Citizen* resident = new Citizen();
    resEstate->setCapacity(10);
    resEstate->moveIn(resident);
    resEstate->moveOut(resident);
    EXPECT_TRUE(resEstate->moveIn(resident));  // Check if the resident can move in again after moving out
    delete resident;
}

TEST_F(ResEstateTest, AddUtility) {
    UtilityManager* utility = new UtilPowerPlants();
    resEstate->addUtility(utility);
    EXPECT_NO_THROW(resEstate->notifyUtilities());
    delete utility;
}

TEST_F(ResEstateTest, SetAndGetState) {
    resEstate->setState(true);
    EXPECT_TRUE(resEstate->getState());
    resEstate->setState(false);
    EXPECT_FALSE(resEstate->getState());
}

TEST_F(ResEstateTest, DisplayBuildingInfo) {
    resEstate->setCapacity(50);
    testing::internal::CaptureStdout();
    resEstate->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Estate for 50 people"), std::string::npos);
}

TEST_F(ResEstateTest, GetBuildingType) {
    EXPECT_EQ(resEstate->getBuildingType(), "Residential Estate");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}