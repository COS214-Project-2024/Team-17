#include <gtest/gtest.h>
#include "../src/Government+Tax/Government.h"
#include "../src/Government+Tax/CitizenTaxAB.h"
#include "../src/Citizens/Citizen.h"
#include "../src/Buildings/Building.h"

class GovernmentTest : public ::testing::Test {
protected:
    Government* government;
    CityStructure* city;

    void SetUp() override {
        government = new Government();
        city = new CityStructure("TestCity");
        city->allocateBudget("Health", 1000); // Initialize budget for testing
        government->addCity(*city);
        government->setTaxRate("Health", 0.10); // 10% tax rate
    }

    void TearDown() override {
        delete government;
        delete city;
    }
};

TEST_F(GovernmentTest, TestProcessTaxes) {
    city->allocateBudget("Health", 1000);
    city->allocateBudget("Education", 2000);
    
    government->processTaxes(*city);
    
    //EXPECT_DOUBLE_EQ(government->getCityTax("TestCity"), 300); // Assuming income = 3000
}

TEST_F(GovernmentTest, TestApplyBudget) {
    government->applyBudget(*city);
    
    //EXPECT_DOUBLE_EQ(city->getDepartments()["Health"], 30); // 10% of 300 = 30
    //EXPECT_DOUBLE_EQ(city->getDepartments()["Education"], 60); // Assuming similar allocation
}

// // Mock classes for Citizen and Building
// class MockCitizen : public Citizen {
// public:
//     MOCK_METHOD(double, getTax, (), (override));
// };

// class MockBuilding : public Building {
// public:
//     MOCK_METHOD(double, getTax, (), (override));  // Adjust if your Building class has a method
// };

// class CitizenTaxABTest : public ::testing::Test {
// protected:
//     CitizenTaxAB* taxVisitor;

//     void SetUp() override {
//         taxVisitor = new CitizenTaxAB();
//     }

//     void TearDown() override {
//         delete taxVisitor;
//     }
// };

// TEST_F(CitizenTaxABTest, VisitCitizenReturnsTax) {
//     MockCitizen citizen;
//     EXPECT_CALL(citizen, getTax()).WillOnce(::testing::Return(150.0));

//     double tax = taxVisitor->visit(&citizen);
//     EXPECT_DOUBLE_EQ(tax, 150.0);
// }

// TEST_F(CitizenTaxABTest, VisitCitizenReturnsZeroForNull) {
//     EXPECT_DOUBLE_EQ(taxVisitor->visit(nullptr), 0.0);
// }

// TEST_F(CitizenTaxABTest, VisitBuildingReturnsZero) {
//     MockBuilding building;
//     // If you want to test the business tax calculation, set expectations here
//     // EXPECT_CALL(building, getTax()).WillOnce(::testing::Return(200.0));

//     double tax = taxVisitor->visit(&building);
//     EXPECT_DOUBLE_EQ(tax, 0.0); // As per your current implementation
// }

// TEST_F(CitizenTaxABTest, VisitBuildingReturnsZeroForNull) {
//     EXPECT_DOUBLE_EQ(taxVisitor->visit(nullptr), 0.0);
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}