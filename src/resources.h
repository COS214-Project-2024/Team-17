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
        int getElectricityUsage();
        int getElectricityGenerated();
        int getWaterUsage();
        int getWaterGenerated();
        double getMoney();
        int getPopulation();

        void addWood(int wood);
        void addSteel(int steel);
        void addConcrete(int concrete);
        void addElectricityUsage(int electricity);
        void addElectricityGenerated(int electricity);
        void addWaterUsage(int water);
        void addWaterGenerated(int water);
        void addMoney(double money);
        void addPopulation(int population);
        void addToMaxPopulation(int population);

        void removeWood(int wood);
        void removeSteel(int steel);
        void removeConcrete(int concrete);
        void removeElectricityUsage(int electricity);
        void removeElectricityGenerated(int electricity);
        void removeWaterUsage(int water);
        void removeWaterGenerated(int water);
        void removeMoney(double money);
        void removePopulation(int population);

    private:
        int woodUnits;
        int steelUnits;
        int concreteUnits;

        int totalElectricityUnitUsage;
        int totalElectricityUnitGenerated;

        int waterUnitsGenerated;
        int waterUnitsUsed;

        double money;

        int maxPopulation;
        int currentPopulation;
};

#endif