#include <gtest/gtest.h>
#include "../src/Buildings/ServHospital.h"
#include "../src/Buildings/ServEducation.h"
#include "../src/Buildings/ServSecurity.h"
#include "../src/Buildings/ServEntertainment.h"

// Test ServHospital creation
TEST(ServHospitalTest, CreateServHospital)
{
    ServHospital *hospital = new ServHospital();
    ASSERT_NE(hospital, nullptr);
    delete hospital;
}

// Test setting and getting visitors
TEST(ServHospitalTest, SetAndGetVisitors)
{
    ServHospital *hospital = new ServHospital();
    hospital->setVisitors(10);
    EXPECT_EQ(hospital->getVisitors(), 10);
    delete hospital;
}

// Test operational state
TEST(ServHospitalTest, SetAndGetState)
{
    ServHospital *hospital = new ServHospital();
    hospital->setState(true);
    EXPECT_TRUE(hospital->getState());
    hospital->setState(false);
    EXPECT_FALSE(hospital->getState());
    delete hospital;
}

// Test adding employees
TEST(ServHospitalTest, AddEmployee)
{
    ServHospital *hospital = new ServHospital();
    Citizen *employee = new Citizen(); // Assuming Citizen has a default constructor
    EXPECT_TRUE(hospital->addEmployee(employee));
    delete employee;
    delete hospital;
}

// Test removing employees
TEST(ServHospitalTest, RemoveEmployee)
{
    ServHospital *hospital = new ServHospital();
    Citizen *employee = new Citizen();
    hospital->addEmployee(employee);
    hospital->removeEmployee(employee); // Remove should succeed
    delete employee;
    delete hospital;
}

// Test calling utilities
TEST(ServHospitalTest, CallUtilities)
{
    ServHospital *hospital = new ServHospital();
    EXPECT_NO_THROW(hospital->callUtilities());
    delete hospital;
}

// Test education service creation
TEST(ServEducationTest, CreateServEducation)
{
    ServEducation *education = new ServEducation();
    ASSERT_NE(education, nullptr);
    delete education;
}

// Test setting and getting visitors
TEST(ServEducationTest, SetAndGetVisitors)
{
    ServEducation *education = new ServEducation();
    education->setVisitors(20);
    EXPECT_EQ(education->getVisitors(), 20);
    delete education;
}

// Test adding and removing employees
TEST(ServEducationTest, AddAndRemoveEmployee)
{
    ServEducation *education = new ServEducation();
    Citizen *employee = new Citizen();
    EXPECT_TRUE(education->addEmployee(employee));
    education->removeEmployee(employee);
    delete employee;
    delete education;
}

// Test security service creation
TEST(ServSecurityTest, CreateServSecurity)
{
    ServSecurity *securityService = new ServSecurity();
    ASSERT_NE(securityService, nullptr);
    delete securityService;
}

// Test setting and getting visitors
TEST(ServSecurityTest, SetAndGetVisitors)
{
    ServSecurity *securityService = new ServSecurity();
    securityService->setVisitors(25);
    EXPECT_EQ(securityService->getVisitors(), 25);

    securityService->setVisitors(10);
    EXPECT_EQ(securityService->getVisitors(), 10);

    delete securityService;
}

// Test adding and removing employees
TEST(ServSecurityTest, AddAndRemoveEmployee)
{
    ServSecurity *securityService = new ServSecurity();
    Citizen *employee = new Citizen();
    EXPECT_TRUE(securityService->addEmployee(employee));
    securityService->removeEmployee(employee);
    delete employee;
    delete securityService;
}

// Test state setting and getting
TEST(ServSecurityTest, SetAndGetState)
{
    ServSecurity *securityService = new ServSecurity();
    securityService->setState(true);
    EXPECT_TRUE(securityService->getState());

    securityService->setState(false);
    EXPECT_FALSE(securityService->getState());
    delete securityService;
}

// Test calling utilities
TEST(ServSecurityTest, CallUtilities)
{
    ServSecurity *securityService = new ServSecurity();
    // Assuming notifyUtilities is a method to check if utilities are called
    EXPECT_NO_THROW(securityService->callUtilities());
    delete securityService;
}

// Test entertainment service creation
TEST(ServEntertainmentTest, CreateServEntertainment)
{
    ServEntertainment *entertainmentService = new ServEntertainment();
    ASSERT_NE(entertainmentService, nullptr);
    delete entertainmentService;
}

// Test setting and getting visitors
TEST(ServEntertainmentTest, SetAndGetVisitors)
{
    ServEntertainment *entertainmentService = new ServEntertainment();
    entertainmentService->setVisitors(30);
    EXPECT_EQ(entertainmentService->getVisitors(), 30);

    entertainmentService->setVisitors(15);
    EXPECT_EQ(entertainmentService->getVisitors(), 15);
    delete entertainmentService;
}

// Test adding and removing employees
TEST(ServEntertainmentTest, AddAndRemoveEmployee)
{
    ServEntertainment *entertainmentService = new ServEntertainment();
    Citizen *employee = new Citizen();
    EXPECT_TRUE(entertainmentService->addEmployee(employee));
    entertainmentService->removeEmployee(employee);
    delete employee;
    delete entertainmentService;
}

// Test state setting and getting
TEST(ServEntertainmentTest, SetAndGetState)
{
    ServEntertainment *entertainmentService = new ServEntertainment();
    entertainmentService->setState(true);
    EXPECT_TRUE(entertainmentService->getState());

    entertainmentService->setState(false);
    EXPECT_FALSE(entertainmentService->getState());
    delete entertainmentService;
}

// Test calling utilities
TEST(ServEntertainmentTest, CallUtilities)
{
    ServEntertainment *entertainmentService = new ServEntertainment();
    // Assuming notifyUtilities is a method to check if utilities are called
    EXPECT_NO_THROW(entertainmentService->callUtilities());
    delete entertainmentService;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
