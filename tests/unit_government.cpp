#include <gtest/gtest.h>
#include "../src/Government+Tax/Government.h"
#include "../src/Government+Tax/CitizenTaxAB.h"
#include "../src/Citizens/Citizen.h"
#include "../src/Buildings/Building.h"

class GovernmentTest : public ::testing::Test
{
protected:
    Government *government;
    CityStructure *city;

    void SetUp() override
    {
        government = new Government();
        city = new CityStructure("TestCity");
        city->allocateBudget("Health", 1000); // Initialize budget for testing
        government->addCity(city);
        government->setTaxRate("Health", 0.10); // 10% tax rate
    }

    void TearDown() override
    {
        delete government;
        delete city;
    }
};

TEST_F(GovernmentTest, TestProcessTaxes)
{
    city->allocateBudget("Health", 1000);
    city->allocateBudget("Education", 2000);

    government->processTaxes(city);
}

TEST_F(GovernmentTest, TestApplyBudget)
{
    government->applyBudget(city);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}