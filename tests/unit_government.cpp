#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Government+Tax/Government.h"
#include "../src/Government+Tax/CitizenTaxAB.h"
#include "../src/Government+Tax/BudgetPolicy.h"
#include "../src/Government+Tax/CityStructure.h"
#include "../src/Government+Tax/TaxManager.h"
#include "../src/Citizens/Citizen.h"
#include "../src/Buildings/Building.h"


// Mock class for CityBlock
class MockCityBlock : public CityBlock {
public:
    MOCK_METHOD(double, accept, (TaxAndBudgetVisitor &visitor));
};

// Mock class for BudgetPolicy
class MockBudgetPolicy : public BudgetPolicy {
public:
    MOCK_METHOD(void, applyBudget, (CityStructure &, double), (override));
};

class CityStructureTest : public ::testing::Test {
protected:
    CityStructure cityStructure{"Metropolis"};
};

// Test: CityStructure::getName should return the correct name
TEST_F(CityStructureTest, GetNameReturnsCorrectName) {
    EXPECT_EQ(cityStructure.getName(), "Metropolis");
}

// Test: CityStructure::getIncome should return the correct income
TEST_F(CityStructureTest, GetIncomeReturnsCorrectValue) {
    EXPECT_DOUBLE_EQ(cityStructure.getIncome(), 0.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}