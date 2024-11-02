#include <gtest/gtest.h>
#include "../src/Buildings/ServHospital.h"

class ServHospitalTest : public ::testing::Test {
protected:
    ServHospital* hospital;

    void SetUp() override {
        hospital = new ServHospital();
    }

    void TearDown() override {
        delete hospital;
    }
};

// Test ServHospital creation
TEST_F(ServHospitalTest, CreateServHospital) {
    ASSERT_NE(hospital, nullptr);
}

// Test setting and getting visitors
TEST_F(ServHospitalTest, SetAndGetVisitors) {
    hospital->setVisitors(10);
    EXPECT_EQ(hospital->getVisitors(), 10);
}

// Test operational state
TEST_F(ServHospitalTest, SetAndGetState) {
    hospital->setState(true);
    EXPECT_TRUE(hospital->getState());
    hospital->setState(false);
    EXPECT_FALSE(hospital->getState());
}

// Test adding employees
TEST_F(ServHospitalTest, AddEmployee) {
    Citizen* employee = new Citizen(); // Assuming Citizen has a default constructor
    EXPECT_TRUE(hospital->addEmployee(employee));
    delete employee;
}

// Test removing employees
TEST_F(ServHospitalTest, RemoveEmployee) {
    Citizen* employee = new Citizen();
    hospital->addEmployee(employee);
    hospital->removeEmployee(employee); // Remove should succeed
    delete employee;
}

// Test calling utilities
TEST_F(ServHospitalTest, CallUtilities) {
    EXPECT_NO_THROW(hospital->callUtilities());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
