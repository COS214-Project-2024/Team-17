#ifndef GAME_H
#define GAME_H

#include "../src/Government+Tax/Government.h"
#include "../src/Government+Tax/TaxManager.h"
#include "../src/Government+Tax/AllocateTaxCommand.h"
#include "../src/Government+Tax/CollectTaxCommand.h"
#include "../src/Government+Tax/SetTaxRateCommand.h"
#include "../src/Citizens/CityCentralMediator.h"
#include "../src/Buildings/ResFlat.h"
#include "../src/Buildings/ResHouse.h"
#include "../src/resources.h"
#include "../src/Policy.h"

#include <QTimer>
class HomePage;
class GameLoop {
public:
    GameLoop();
    void start(HomePage* homePage);
private:
    Government gov;
    // TaxManager taxManager;
    CityCentralMediator* mediator = nullptr;
    bool running;
    int counter = 0;
    void updateTransport();
    void updateJobs();
    void updateCityGrowth();
    int time_of_day = 0;
    bool game = true;
};

#endif // GAME_H
