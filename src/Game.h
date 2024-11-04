#ifndef GAME_H
#define GAME_H

#include "./Government+Tax/Government.h"
#include "./Government+Tax/TaxManager.h"
#include "./Government+Tax/AllocateTaxCommand.h"
#include "./Government+Tax/CollectTaxCommand.h"
#include "./Government+Tax/SetTaxRateCommand.h"
#include "./Citizens/CityCentralMediator.h"
#include "./Buildings/ResFlat.h"
#include "./Buildings/ResHouse.h"
#include "resources.h"
#include "Policy.h"
/**
 * @class Game
 * @brief Represents the main game logic and management for the simulation.
 *
 * The Game class is responsible for initializing and running the simulation,
 * managing government functions, tax collection, and updates to city dynamics.
 */
class Game
{
public:
    /**
     * @brief Constructs the Game object and initializes necessary components.
     */
    Game();
    /**
     * @brief Starts the game loop, allowing the simulation to run.
     * 
     * This method will continuously update the game state until the game is stopped.
     */
    void start();

private:
    Government gov;
    TaxManager taxManager;
    CityCentralMediator* mediator = nullptr;
    bool running;
    int counter = 0;
    /**
     * @brief Updates the transport systems within the city.
     * 
     * This method manages the state and efficiency of transport in the city.
     */
    void updateTransport();
    /**
     * @brief Updates job availability and workforce dynamics in the city.
     * 
     * This method adjusts the job market based on city growth and citizen needs.
     */
    void updateJobs();
    /**
     * @brief Updates the growth metrics of the city.
     * 
     * This method manages population and infrastructure growth within the simulation.
     */
    void updateCityGrowth();
    /**
     * @brief Updates the city's tax system based on current economic conditions.
     * 
     * This method collects taxes and adjusts tax rates as necessary.
     */
    void updateCityTax();
};

#endif // GAME_H