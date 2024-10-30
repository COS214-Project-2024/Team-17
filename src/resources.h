#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>

using namespace std;

struct Resources{
    public:
        static int getWood();
        static int getSteel();
        static int getConcrete();
        static int getElectricityUsage();
        static int getElectricityGenerated();
        static int getWaterUsage();
        static int getWaterGenerated();
        static double getMoney();
        static int getPopulation();

        static void addWood(int wood);
        static void addSteel(int steel);
        static void addConcrete(int concrete);
        static void addElectricityUsage(int electricity);
        static void addElectricityGenerated(int electricity);
        static void addWaterUsage(int water);
        static void addWaterGenerated(int water);
        static void addMoney(double Addedmoney);
        static void addPopulation(int population);
        static void addToMaxPopulation(int population);

        static void removeWood(int wood);
        static void removeSteel(int steel);
        static void removeConcrete(int concrete);
        static void removeElectricityUsage(int electricity);
        static void removeElectricityGenerated(int electricity);
        static void removeWaterUsage(int water);
        static void removeWaterGenerated(int water);
        static void removeMoney(double Addedmoney);
        static void removePopulation(int population);

    private:
        static int woodUnits;
        static int steelUnits;
        static int concreteUnits;

        static int totalElectricityUnitUsage;
        static int totalElectricityUnitGenerated;

        static int waterUnitsGenerated;
        static int waterUnitsUsed;

        static double money;

        static int maxPopulation;
        static int currentPopulation;
};

#endif