#ifndef GAME_H
#define GAME_H

#include "./Government+Tax/Government.h"
#include "./Government+Tax/TaxManager.h"
#include "./Government+Tax/AllocateTaxCommand.h"
#include "./Government+Tax/CollectTaxCommand.h"
#include "./Government+Tax/SetTaxRateCommand.h"
#include "Policy.h"

class Game
{
public:
    Game();
    void start();

private:
    Government gov;
    TaxManager taxManager;
    bool running;
    int counter = 0;
    void updateTransport();
    void updateConstruction();
    void updateJobs();
    void updateCityGrowth();
    void updateCityTax();
};

#endif // GAME_H