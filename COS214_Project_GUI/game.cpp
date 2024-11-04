#include "game.h"
#include "homepage.h"

#include <chrono>
#include <thread>

#include "../src/Citizens/CitizensIncludes.h"

static constexpr int GAME_SPEED = 17;
static constexpr int TRANSPORT_UPDATE_INTERVAL = 1;
static constexpr int CONSTRUCTION_UPDATE_INTERVAL = 60;
static constexpr int JOB_UPDATE_INTERVAL = 6;
static constexpr int CITY_GROWTH_INTERVAL = 240;
static constexpr int CITY_TAX_INTERVAL = 240;

GameLoop::GameLoop() {
    Resources::removePopulation(Resources::getPopulation());
    this->mediator = CityCentralMediator::getInstance();
    delete mediator;
    this->mediator = CityCentralMediator::getInstance();
    CityStructure *city = new CityStructure("Pretoria");
    city->addBlock(new CityBlock());
    this->gov.addCity(*city);
}

void GameLoop::start(HomePage* homePage){
    counter = 0;
    while (running)
    {
        // if (counter % TRANSPORT_UPDATE_INTERVAL == 0)
        // {
        //     time_of_day++;
        //     if (time_of_day > 24)
        //     {
        //         time_of_day = 0;
        //     }
        //     // updateTransport();
        // }
        // if (counter % JOB_UPDATE_INTERVAL == 0)
        // {
        //     updateJobs();
        // }
        // if (counter % CITY_GROWTH_INTERVAL == 0)
        // {
        //     updateCityGrowth();
        // }
        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(GAME_SPEED));
    }
}

void GameLoop::updateTransport()
{
    if (mediator)
    {
        mediator->updateBuses();
    }
}

void GameLoop::updateJobs()
{
    if (mediator)
    {
        if (time_of_day == 8)
        {
            mediator->citizensStartWork();
        }
        if (time_of_day == 17)
        {
            mediator->citizensEndWork();
        }
    }
}

void GameLoop::updateCityGrowth()
{
    if (mediator)
    {
        std::cout << "=======citizensDoSomething=======" << std::endl;

        mediator->citizensDoSomething();
        std::cout << "=======handlePopulationGrowth=======" << std::endl;

        mediator->handlePopulationGrowth();
        std::cout << "=======updateSatisfaction=======" << std::endl;

        mediator->updateCitizenSatisfaction();

        std::cout << "all done" << std::endl;
    }
}
