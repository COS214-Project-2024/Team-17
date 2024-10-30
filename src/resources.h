#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>

using namespace std;

struct Resources{
    public:
        //getters
        static int getWood();
        static int getWoodPerTick();

        static int getSteel();
        static int getSteelPerTick();

        static int getConcrete();
        static int getConcretePerTick();

        static int getElectricityUsage();
        static int getElectricityGenerated();

        static int getWaterUsage();
        static int getWaterGenerated();

        static double getMoney();
        static double getIncome();

        static int getPopulation();
        static int getMaxPopulation();

        //adding resources
        static int getHappiness();

        static void addWood(int wood);
        static void addWoodPerTick(int wood);

        static void addSteel(int steel);
        static void addSteelPerTick(int steel);

        static void addConcrete(int concrete);
        static void addConcretePerTick(int concrete);

        static void addElectricityUsage(int electricity);
        static void addElectricityGenerated(int electricity);

        static void addWaterUsage(int water);
        static void addWaterGenerated(int water);

        static void addMoney(double Addedmoney);
        static void addIncome(double income);

        static void addMoney(double Addedmoney); // total money you have
        static void addIncome(double income); // amount generated
        static void addPopulation(int population);
        static void addToMaxPopulation(int population);

        //removing resources
        static void addHappiness(int happiness);

        static void removeWood(int wood);
        static void removeWoodPerTick(int wood);

        static void removeSteel(int steel);
        static void removeSteelPerTick(int steel);

        static void removeConcrete(int concrete);
        static void removeConcretePerTick(int concrete);

        static void removeElectricityUsage(int electricity);
        static void removeElectricityGenerated(int electricity);

        static void removeWaterUsage(int water);
        static void removeWaterGenerated(int water);

        static void removeMoney(double Addedmoney);
        static void removeIncome(double income);
        
        static void removeMoney(double Addedmoney); // cost
        static void removeIncome(double income); // income
        static void removePopulation(int population);
        static void removeFromMaxPopulation(int population);
        static void removeHappiness(int happiness);

    private:
        static int woodUnits;
        static int woodUnitsPerTick;

        static int steelUnits;
        static int steelUnitsPerTick;

        static int concreteUnits;
        static int concreteUnitsPerTick;

        static int totalElectricityUnitUsage;
        static int totalElectricityUnitGenerated;

        static int waterUnitsGenerated;
        static int waterUnitsUsed;

        static double tickIncome;
        static double money;

        static int maxPopulation;
        static int currentPopulation;

        static int happinessUnits;
};

#endif