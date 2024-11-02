#include <gtest/gtest.h>

#include "../src/Citizens/CitizensIncludes.h"
#include "../src/Transport/TransportInclude.h"
#include "../src/Buildings/ResFlat.h"

TEST(PopulationGrowth, IncreasePopulation)
{
    CityCentralMediator *mediator = CityCentralMediator::getInstance();

    Building *building = new ResFlat();

    ASSERT_EQ(Resources::getPopulation(), 0);

    mediator->handlePopulationGrowth();

    std::cout << "Population: " << Resources::getPopulation() << std::endl;

    delete building;
    delete mediator;
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}