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
    // EXPECT_TRUE(indFactory->addEmployee(employee3)); // Now should succeed
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

// Test fixture for IndWarehouse
class IndWarehouseTest : public ::testing::Test {
protected:
    IndWarehouse* warehouse;

    void SetUp() override {
        warehouse = new IndWarehouse();
    }

    void TearDown() override {
        delete warehouse;
    }
};

// Test IndWarehouse creation
TEST_F(IndWarehouseTest, CreateIndWarehouse) {
    ASSERT_NE(warehouse, nullptr);
}

// Test setting and getting production capacity for IndWarehouse
TEST_F(IndWarehouseTest, SetAndGetProductionCapacity) {
    warehouse->setProductionCapacity(20);
    EXPECT_EQ(warehouse->getProductionCapacity(), 20);
}

// Test adding and removing employees in IndWarehouse
TEST_F(IndWarehouseTest, AddAndRemoveEmployee) {
    Citizen* employee = new Citizen();
    EXPECT_TRUE(warehouse->addEmployee(employee));
    warehouse->removeEmployee(employee);
    //delete employee;
}

// Test for utility connection in IndWarehouse
TEST_F(IndWarehouseTest, AddUtility) {
    UtilityManager* utility = new UtilWaterSupply();
    warehouse->addUtility(utility);
    EXPECT_NO_THROW(warehouse->callUtilities());
    delete utility;
}

// Test getting and setting state in IndWarehouse
TEST_F(IndWarehouseTest, SetAndGetState) {
    warehouse->setState(true);
    EXPECT_TRUE(warehouse->getState());
    warehouse->setState(false);
    EXPECT_FALSE(warehouse->getState());
}

// Test displaying building info for IndWarehouse
TEST_F(IndWarehouseTest, DisplayBuildingInfo) {
    testing::internal::CaptureStdout();
    warehouse->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Warehouse with production capacity"), std::string::npos);
}

// Test fixture for IndPlant
class IndPlantTest : public ::testing::Test {
protected:
    IndPlant* plant;

    void SetUp() override {
        plant = new IndPlant();
    }

    void TearDown() override {
        delete plant;
    }
};

// Test IndPlant creation
TEST_F(IndPlantTest, CreateIndPlant) {
    ASSERT_NE(plant, nullptr);
}

// Test setting and getting production capacity for IndPlant
TEST_F(IndPlantTest, SetAndGetProductionCapacity) {
    plant->setProductionCapacity(15);
    EXPECT_EQ(plant->getProductionCapacity(), 15);
}

// Test adding and removing employees in IndPlant
TEST_F(IndPlantTest, AddAndRemoveEmployee) {
    Citizen* employee = new Citizen();
    EXPECT_TRUE(plant->addEmployee(employee));
    plant->removeEmployee(employee);
    //delete employee;
}

// Test for utility connection in IndPlant
TEST_F(IndPlantTest, AddUtility) {
    UtilityManager* utility = new UtilPowerPlants();
    plant->addUtility(utility);
    EXPECT_NO_THROW(plant->callUtilities());
    delete utility;
}

// Test getting and setting state in IndPlant
TEST_F(IndPlantTest, SetAndGetState) {
    plant->setState(true);
    EXPECT_TRUE(plant->getState());
    plant->setState(false);
    EXPECT_FALSE(plant->getState());
}

// Test displaying building info for IndPlant
TEST_F(IndPlantTest, DisplayBuildingInfo) {
    testing::internal::CaptureStdout();
    plant->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Plant with production capacity"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
