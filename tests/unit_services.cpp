#include <gtest/gtest.h>
#include "../src/Buildings/ServHospital.h"
#include "../src/Buildings/ServEducation.h"
#include "../src/Buildings/ServSecurity.h"
#include "../src/Buildings/ServEntertainment.h"

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

TEST_F(ServHospitalTest, CreateServHospital) {
    ASSERT_NE(hospital, nullptr);
}

TEST_F(ServHospitalTest, SetAndGetVisitors) {
    hospital->setVisitors(10);
    EXPECT_EQ(hospital->getVisitors(), 10);
}

TEST_F(ServHospitalTest, SetAndGetState) {
    hospital->setState(true);
    EXPECT_TRUE(hospital->getState());
    hospital->setState(false);
    EXPECT_FALSE(hospital->getState());
}

TEST_F(ServHospitalTest, AddEmployee) {
    Citizen* employee = new Citizen();
    EXPECT_TRUE(hospital->addEmployee(employee));
    delete employee;
}

TEST_F(ServHospitalTest, RemoveEmployee) {
    Citizen* employee = new Citizen();
    hospital->addEmployee(employee);
    hospital->removeEmployee(employee);
    delete employee;
}

TEST_F(ServHospitalTest, CallUtilities) {
    EXPECT_NO_THROW(hospital->callUtilities());
}

class ServEducationTest : public ::testing::Test {
protected:
    ServEducation* education;

    void SetUp() override {
        education = new ServEducation();
    }

    void TearDown() override {
        delete education;
    }
};

TEST_F(ServEducationTest, CreateServEducation) {
    ASSERT_NE(education, nullptr);
}

TEST_F(ServEducationTest, SetAndGetVisitors) {
    education->setVisitors(20);
    EXPECT_EQ(education->getVisitors(), 20);
}

TEST_F(ServEducationTest, AddAndRemoveEmployee) {
    Citizen* employee = new Citizen();
    EXPECT_TRUE(education->addEmployee(employee));
    education->removeEmployee(employee);
    delete employee;
}

class ServSecurityTest : public ::testing::Test {
protected:
    ServSecurity* securityService;

    void SetUp() override {
        securityService = new ServSecurity();
    }

    void TearDown() override {
        delete securityService;
    }
};

TEST_F(ServSecurityTest, CreateServSecurity) {
    ASSERT_NE(securityService, nullptr);
}

TEST_F(ServSecurityTest, SetAndGetVisitors) {
    securityService->setVisitors(25);
    EXPECT_EQ(securityService->getVisitors(), 25);
    
    securityService->setVisitors(10);
    EXPECT_EQ(securityService->getVisitors(), 10);
}

TEST_F(ServSecurityTest, AddAndRemoveEmployee) {
    Citizen* employee = new Citizen();
    EXPECT_TRUE(securityService->addEmployee(employee));
    securityService->removeEmployee(employee);
    delete employee;
}

TEST_F(ServSecurityTest, SetAndGetState) {
    securityService->setState(true);
    EXPECT_TRUE(securityService->getState());
    
    securityService->setState(false);
    EXPECT_FALSE(securityService->getState());
}

TEST_F(ServSecurityTest, CallUtilities) {
    EXPECT_NO_THROW(securityService->callUtilities());
}

class ServEntertainmentTest : public ::testing::Test {
protected:
    ServEntertainment* entertainmentService;

    void SetUp() override {
        entertainmentService = new ServEntertainment();
    }

    void TearDown() override {
        delete entertainmentService;
    }
};

TEST_F(ServEntertainmentTest, CreateServEntertainment) {
    ASSERT_NE(entertainmentService, nullptr);
}

TEST_F(ServEntertainmentTest, SetAndGetVisitors) {
    entertainmentService->setVisitors(30);
    EXPECT_EQ(entertainmentService->getVisitors(), 30);
    
    entertainmentService->setVisitors(15);
    EXPECT_EQ(entertainmentService->getVisitors(), 15);
}

TEST_F(ServEntertainmentTest, AddAndRemoveEmployee) {
    Citizen* employee = new Citizen();
    EXPECT_TRUE(entertainmentService->addEmployee(employee));
    entertainmentService->removeEmployee(employee);
    delete employee;
}

TEST_F(ServEntertainmentTest, SetAndGetState) {
    entertainmentService->setState(true);
    EXPECT_TRUE(entertainmentService->getState());
    
    entertainmentService->setState(false);
    EXPECT_FALSE(entertainmentService->getState());
}

TEST_F(ServEntertainmentTest, CallUtilities) {
    EXPECT_NO_THROW(entertainmentService->callUtilities());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
