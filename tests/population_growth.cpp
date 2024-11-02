#include <gtest/gtest.h>

#include "../src/Citizens/CitizensIncludes.h"
#include "../src/Transport/TransportInclude.h"
#include "../src/Buildings/ResFlat.h"

TEST(PopulationGrowth, IncreasePopulation)
{
    Resources::removePopulation(Resources::getPopulation());

    CityCentralMediator *mediator = CityCentralMediator::getInstance();

    Building *building = new ResFlat();

    ASSERT_EQ(Resources::getPopulation(), 0);

    mediator->handlePopulationGrowth();

    // ASSERT_EQ(Resources::getPopulation(), 2);

    delete building;
    delete mediator;
}

TEST(PopulationGrowth, DecreasePopulation)
{
    Resources::removePopulation(Resources::getPopulation());

    CityCentralMediator *mediator = CityCentralMediator::getInstance();

    Building *building = new ResFlat();

    ASSERT_EQ(Resources::getPopulation(), 0);

    Citizen *citizen = new Citizen();

    ASSERT_EQ(Resources::getPopulation(), 1);

    citizen->fired();
    citizen->fired();
    citizen->fired();

    ASSERT_EQ(Resources::getPopulation(), 0);

    delete building;
    delete mediator;
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}