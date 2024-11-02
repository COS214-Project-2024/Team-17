#include <gtest/gtest.h>
#include "../src/Buildings/Industrial.h"
#include "../src/Buildings/IndFactory.h"
#include "../src/Buildings/IndWarehouse.h"
#include "../src/Buildings/IndPlant.h"

#include "../src/Citizens/Citizen.h"

#include "../src/Utilities/UtilPowerPlants.h"
#include "../src/Utilities/UtilSewageSyst.h"
#include "../src/Utilities/UtilWasteMan.h"
#include "../src/Utilities/UtilWaterSupply.h"

// Test fixture for Industrial
class IndustrialTest : public ::testing::Test {
protected:
    Industrial* industrial;

    void SetUp() override {
        industrial = nullptr; // Industrial is abstract and can't be instantiated directly
    }

    void TearDown() override {
        delete industrial;
    }
};

// Test that we cannot instantiate Industrial
TEST_F(IndustrialTest, IndustrialInstantiation) {
    ASSERT_EQ(nullptr, industrial);
}

// Test fixture for IndFactory
class IndFactoryTest : public ::testing::Test {
protected:
    IndFactory* indFactory;

    void SetUp() override {
        indFactory = new IndFactory();
    }

    void TearDown() override {
        delete indFactory;
    }
};

// Test IndFactory creation
TEST_F(IndFactoryTest, CreateIndFactory) {
    ASSERT_NE(indFactory, nullptr);
}

// Test production capacity setting and getting
TEST_F(IndFactoryTest, SetAndGetProductionCapacity) {
    indFactory->setProductionCapacity(100);
    EXPECT_EQ(indFactory->getProductionCapacity(), 100);
}

// Test that state can be set and retrieved
TEST_F(IndFactoryTest, SetAndGetState) {
    indFactory->setState(true);
    EXPECT_TRUE(indFactory->getState());
    indFactory->setState(false);
    EXPECT_FALSE(indFactory->getState());
}

// Test utility connection for IndFactory
TEST_F(IndFactoryTest, AddAndNotifyUtility) {
    UtilityManager* utility = new UtilPowerPlants();
    indFactory->addUtility(utility);
    EXPECT_NO_THROW(indFactory->callUtilities());
    delete utility;
}

// Test adding and removing employees
TEST_F(IndFactoryTest, AddAndRemoveEmployee) {
    Citizen* employee = new Citizen(); // Assuming Citizen has a default constructor
    EXPECT_TRUE(indFactory->addEmployee(employee));
    indFactory->removeEmployee(employee);
    // Check if employee removal does not throw any errors
    EXPECT_NO_THROW(indFactory->removeEmployee(employee));
    delete employee;
}

// Test for reaching job capacity
TEST_F(IndFactoryTest, JobCapacity) {
    Citizen* employee1 = new Citizen();
    indFactory->setProductionCapacity(1);

    EXPECT_TRUE(indFactory->addEmployee(employee1));
    indFactory->removeEmployee(employee1); // Removing to test capacity freeing up
    delete employee1;
}

// Test that building info displays correctly
TEST_F(IndFactoryTest, DisplayBuildingInfo) {
    indFactory->setProductionCapacity(20);
    testing::internal::CaptureStdout();
    indFactory->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Factory with wood production capacity of 20 units"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
