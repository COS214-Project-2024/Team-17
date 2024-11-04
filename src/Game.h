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
    Game();
    void start();

private:
    Government gov;
    TaxManager taxManager;
    CityCentralMediator *mediator = nullptr;
    bool running;
    int counter = 0;
    void updateTransport();
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