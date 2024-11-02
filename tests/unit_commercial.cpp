// This will test Commercial buildings

#include <gtest/gtest.h>
#include "../src/Buildings/Commercial.h"
#include "../src/Buildings/ComShop.h"
#include "../src/Buildings/ComShop.h"
#include "../src/Buildings/ComOffice.h"
#include "../src/Buildings/ComMall.h"

#include "../src/Citizens/Citizen.h"

#include "../src/Utilities/UtilPowerPlants.h"
#include "../src/Utilities/UtilSewageSyst.h"
#include "../src/Utilities/UtilWasteMan.h"
#include "../src/Utilities/UtilWaterSupply.h"

// Test fixture for ComShop
class ComShopTest : public ::testing::Test {
protected:
    ComShop* comShop;

    void SetUp() override {
        comShop = new ComShop();
    }

    void TearDown() override {
        delete comShop;
    }
};

// Test ComShop creation
TEST_F(ComShopTest, CreateComShop) {
    ASSERT_NE(comShop, nullptr);
}

// Test job capacity setting and getting
TEST_F(ComShopTest, SetAndGetJobCapacity) {
    comShop->setJobCapacity(15);
    EXPECT_EQ(comShop->getJobCapacity(), 15);
}

// Test adding and removing employees
TEST_F(ComShopTest, AddAndRemoveEmployee) {
    Citizen* employee1 = new Citizen();
    Citizen* employee2 = new Citizen();
    
    comShop->setJobCapacity(2);
    EXPECT_TRUE(comShop->addEmployee(employee1));
    EXPECT_TRUE(comShop->addEmployee(employee2));
    EXPECT_FALSE(comShop->addEmployee(new Citizen()));  // Exceed capacity

    comShop->removeEmployee(employee1);
    EXPECT_TRUE(comShop->addEmployee(new Citizen()));  // Should be possible again

    delete employee1;
    delete employee2;
}

// Test for utility connection in ComShop
TEST_F(ComShopTest, AddAndNotifyUtilities) {
    UtilityManager* utility = new UtilPowerPlants();
    comShop->addUtility(utility);
    
    EXPECT_NO_THROW(comShop->callUtilities());  // Verify utilities are notified without error

    delete utility;
}

// Test that ComShop state can be set and retrieved
TEST_F(ComShopTest, SetAndGetState) {
    comShop->setState(true);
    EXPECT_TRUE(comShop->getState());
    comShop->setState(false);
    EXPECT_FALSE(comShop->getState());
}

// Test that building info is displayed correctly
TEST_F(ComShopTest, DisplayBuildingInfo) {
    comShop->setJobCapacity(8);
    testing::internal::CaptureStdout();  // Capture the output
    comShop->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Shop with 8 jobs"), std::string::npos);
}


// Test fixture for ComOffice
class ComOfficeTest : public ::testing::Test {
protected:
    ComOffice* comOffice;

    void SetUp() override {
        comOffice = new ComOffice();
    }

    void TearDown() override {
        delete comOffice;
    }
};

// Test ComOffice creation
TEST_F(ComOfficeTest, CreateComOffice) {
    ASSERT_NE(comOffice, nullptr);
}

// Test setting and getting job capacity
TEST_F(ComOfficeTest, SetAndGetJobCapacity) {
    comOffice->setJobCapacity(25);
    EXPECT_EQ(comOffice->getJobCapacity(), 25);
}

// Test adding and removing an employee
TEST_F(ComOfficeTest, AddAndRemoveEmployee) {
    Citizen* employee = new Citizen();
    EXPECT_TRUE(comOffice->addEmployee(employee));
    comOffice->removeEmployee(employee);
    delete employee;
}

// Test utility connection for ComOffice
TEST_F(ComOfficeTest, AddUtility) {
    UtilityManager* utility = new UtilWaterSupply();
    comOffice->addUtility(utility);
    EXPECT_NO_THROW(comOffice->notifyUtilities());
    delete utility;
}

// Test ComOffice state
TEST_F(ComOfficeTest, SetAndGetState) {
    comOffice->setState(true);
    EXPECT_TRUE(comOffice->getState());
    comOffice->setState(false);
    EXPECT_FALSE(comOffice->getState());
}

// Test ComOffice info display
TEST_F(ComOfficeTest, DisplayBuildingInfo) {
    comOffice->setJobCapacity(12);
    testing::internal::CaptureStdout();
    comOffice->displayBuildingInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Office with 12 jobs"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
