#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    void start();

private:
    bool running;
    int counter = 0;
    void updateTransport();
    void updateConstruction();
    void updateJobs();
    void updateCityGrowth();
    void updateCityTax();
};

#endif // GAME_H