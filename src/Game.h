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
#include "./Buildings/FactoryBuilding.h"
#include "./Buildings/FactResidential.h"
#include "./Buildings/FactCommercial.h"
#include "./Buildings/FactIndustrial.h"
#include "./Buildings/FactLandmarks.h"
#include "./Buildings/FactService.h"
#include "resources.h"
#include "Policy.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class Game
{
public:
    /**
     * @brief Constructs the Game object and initializes necessary components.
     */
    Game();

    /**
     * @brief Destroys the Game object and cleans up any resources.
     */
    ~Game();
    /**
     * @brief Starts the game loop, allowing the simulation to run.
     * 
     * This method will continuously update the game state until the game is stopped.
     */
    void start();

private:
    Government gov;
    TaxManager taxManager;
    CityCentralMediator *mediator = nullptr;
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
    void citizensDoSomething();
    void updateCityTax();
    void citizensGoToWork();
    void citizensGoHome();
    void updateCityGrowth();
    int promptUserAction();
    bool isValidNumber(const string &input, int &number);
    bool intersectionOccupied[20][20] = {false}; // Tracks occupied intersections
    std::pair<int, int> findNextFreeIntersection();
    int numBuildings = 0;
    const int MAX_BUILDINGS = 380; // 20x19 intersections

    struct BuildingOption
    {
        string type;
        vector<string> subtypes;
    };
    void createBuilding();
    vector<BuildingOption> buildingOptions;
    void initBuildingOptions();
    void initRoadGrid();
};

#endif // GAME_H