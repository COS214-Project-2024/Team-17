#include "Game.h"
#include <chrono>
#include <thread>
#include <iostream>

static constexpr int GAME_SPEED = 17;                   // millisecond timeout
static constexpr int TRANSPORT_UPDATE_INTERVAL = 1;     // Every 10 minutes
static constexpr int CONSTRUCTION_UPDATE_INTERVAL = 60; // Every 6 hours
static constexpr int JOB_UPDATE_INTERVAL = 6;           // Every 1 hour
static constexpr int CITY_GROWTH_INTERVAL = 240;        // Every 1 day
static constexpr int CITY_TAX_INTERVAL = 240;           // Every 1 day

Game::Game()
{
}

void Game::updateTransport()
{
    std::cout << "Transport updated" << std::endl;
}

void Game::updateConstruction()
{
    std::cout << "Construction updated" << std::endl;
}

void Game::updateJobs()
{
    std::cout << "Jobs updated" << std::endl;
}

void Game::updateCityGrowth()
{
    std::cout << "City growth updated" << std::endl;
}

void Game::updateCityTax()
{
    std::cout << "City tax updated" << std::endl;
}

void Game::start()
{
    running = true;
    counter = 0;
    while (running)
    {
        if (counter % TRANSPORT_UPDATE_INTERVAL == 0)
        {
            updateTransport();
        }
        if (counter % CONSTRUCTION_UPDATE_INTERVAL == 0)
        {
            updateConstruction();
        }
        if (counter % JOB_UPDATE_INTERVAL == 0)
        {
            updateJobs();
        }
        if (counter % CITY_GROWTH_INTERVAL == 0)
        {
            updateCityGrowth();
        }
        if (counter % CITY_TAX_INTERVAL == 0)
        {
            updateCityTax();
        }
        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(GAME_SPEED));
    }
}