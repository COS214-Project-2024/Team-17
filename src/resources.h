#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>

using namespace std;

class Resources{
    public:
        Resources();
        ~Resources();

        int getWood();
        int getSteel();
        int getConcrete();
        int getElectricity();
        int getWater();
        double getMoney();
        int getPopulation();

        void addWood(int wood);
        void addSteel(int steel);
        void addConcrete(int concrete);
        void addElectricity(int electricity);
        void addWater(int water);
        void addMoney(double money);
        void addPopulation(int population);
        void addToMaxPopulation(int population);

        void removeWood(int wood);
        void removeSteel(int steel);
        void removeConcrete(int concrete);
        void removeElectricity(int electricity);
        void removeWater(int water);
        void removeMoney(double money);
        void removePopulation(int population);

    private:
        int woodUnits;
        int steelUnits;
        int concreteUnits;

        int electricityUnits;
        int waterUnits;

        double money;

        int maxPopulation;
        int currentPopulation;
};

#endif