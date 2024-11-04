#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>

using namespace std;
/**
 * @struct Resources
 * @brief Manages the city's resources, including materials, utilities, and finances.
 *
 * This struct provides static methods to get and modify various resources
 * such as wood, steel, concrete, electricity, water, money, and population.
 */
struct Resources{
    public:
        //getters    
    /**
     * @brief Gets the current amount of wood.
     * @return The current amount of wood.
     */
        static int getWood();
    /**
     * @brief Gets the amount of wood generated per tick.
     * @return The amount of wood generated per tick.
     */
        static int getWoodPerTick();
    /**
     * @brief Gets the current amount of steel.
     * @return The current amount of steel.
     */
        static int getSteel();
    /**
     * @brief Gets the amount of steel generated per tick.
     * @return The amount of steel generated per tick.
     */
        static int getSteelPerTick();
    /**
     * @brief Gets the current amount of concrete.
     * @return The current amount of concrete.
     */
        static int getConcrete();
    /**
     * @brief Gets the amount of concryete generated per tick.
     * @return The amount of concrete generated per tick.
     */
        static int getConcretePerTick();
    /**
     * @brief Gets the total electricity usage.
     * @return The total electricity usage.
     */
        static int getElectricityUsage();
        /**
     * @brief Gets the total electricity generated.
     * @return The total electricity generated.
     */
        static int getElectricityGenerated();
    /**
     * @brief Gets the total water usage.
     * @return The total water usage.
     */
        static int getWaterUsage();
        /**
     * @brief Gets the total water generated.
     * @return The total water generated.
     */
        static int getWaterGenerated();
    /**
     * @brief Gets the current amount of money.
     * @return The current amount of money.
     */
        static double getMoney();
    /**
     * @brief Gets the total income generated.
     * @return The total income generated.
     */
        static double getIncome();
    /**
     * @brief Gets the current population.
     * @return The current population.
     */
        static int getPopulation();
    /**
     * @brief Gets the maximum population capacity.
     * @return The maximum population capacity.
     */
        static int getMaxPopulation();

        //adding resources
 
    /**
     * @brief Gets the current happiness level.
     * @return The current happiness level.
     */
        static int getHappiness();
    /**
     * @brief Adds wood to the total amount.
     * @param wood Amount of wood to add.
     */
        static void addWood(int wood);
    /**
     * @brief Adds to the wood generated per tick.
     * @param wood Amount of wood to add per tick.
     */
        static void addWoodPerTick(int wood);
    /**
     * @brief Adds steel to the total amount.
     * @param steel Amount of steel to add.
     */
        static void addSteel(int steel);
    /**
     * @brief Adds to the steel generated per tick.
     * @param steel Amount of steel to add per tick.
     */
        static void addSteelPerTick(int steel);
    /**
     * @brief Adds concrete to the total amount.
     * @param concrete Amount of concrete to add.
     */
        static void addConcrete(int concrete);
    /**
     * @brief Adds to the concrete generated per tick.
     * @param concrete Amount of concrete to add per tick.
     */
        static void addConcretePerTick(int concrete);
    /**
     * @brief Adds to the electricity usage.
     * @param electricity Amount of electricity to add to usage.
     */
        static void addElectricityUsage(int electricity);
    /**
     * @brief Adds to the electricity generated.
     * @param electricity Amount of electricity to add to generation.
     */
        static void addElectricityGenerated(int electricity);
    /**
     * @brief Adds to the water usage.
     * @param water Amount of water to add to usage.
     */
        static void addWaterUsage(int water);
    /**
     * @brief Adds to the water generated.
     * @param water Amount of water to add to generation.
     */
        static void addWaterGenerated(int water);
    /**
     * @brief Adds to the total money available.
     * @param Addedmoney Amount of money to add.
     */
        static void addMoney(double Addedmoney); // total money you have
    /**
     * @brief Adds to the total income generated.
     * @param income Amount of income to add.
     */
        static void addIncome(double income); // amount generated
    /**
     * @brief Adds to the current population.
     * @param population Amount of population to add.
     */
        static void addPopulation(int population);
    /**
     * @brief Increases the maximum population capacity.
     * @param population Amount to add to the max population.
     */
        static void addToMaxPopulation(int population);

        //removing resources
        
    /**
     * @brief Adds to the current happiness level.
     * @param happiness Amount of happiness to add.
     */
        static void addHappiness(int happiness);

    /**
     * @brief Removes wood from the total amount.
     * @param wood Amount of wood to remove.
     */
        static void removeWood(int wood);
    /**
     * @brief Removes from the wood generated per tick.
     * @param wood Amount of wood to remove from per tick generation.
     */
        static void removeWoodPerTick(int wood);
    /**
     * @brief Removes steel from the total amount.
     * @param steel Amount of steel to remove.
     */
        static void removeSteel(int steel);
    /**
     * @brief Removes from the steel generated per tick.
     * @param steel Amount of steel to remove from per tick generation.
     */
        static void removeSteelPerTick(int steel);
    /**
     * @brief Removes concrete from the total amount.
     * @param concrete Amount of concrete to remove.
     */
        static void removeConcrete(int concrete);
    /**
     * @brief Removes from the concrete generated per tick.
     * @param concrete Amount of concrete to remove from per tick generation.
     */
        static void removeConcretePerTick(int concrete);
    /**
     * @brief Removes from the total electricity usage.
     * @param electricity Amount of electricity to remove from usage.
     */
        static void removeElectricityUsage(int electricity);
    /**
     * @brief Removes from the total electricity generated.
     * @param electricity Amount of electricity to remove from generation.
     */
        static void removeElectricityGenerated(int electricity);
    /**
     * @brief Removes from the total water usage.
     * @param water Amount of water to remove from usage.
     */
        static void removeWaterUsage(int water);
    /**
     * @brief Removes from the total water generated.
     * @param water Amount of water to remove from generation.
     */
        static void removeWaterGenerated(int water);
    /**
     * @brief Removes from the total amount of money available.
     * @param Addedmoney Amount of money to remove.
     */
        static void removeMoney(double Addedmoney); // cost
    /**
     * @brief Removes from the total income generated.
     * @param income Amount of income to remove.
     */
        static void removeIncome(double income); // income
    /**
     * @brief Removes from the current population.
     * @param population Amount of population to remove.
     */
    static void removePopulation(int population);

    /**
     * @brief Decreases the maximum population capacity.
     * @param population Amount to remove from the max population.
     */
    static void removeFromMaxPopulation(int population);

    /**
     * @brief Removes from the current happiness level.
     * @param happiness Amount of happiness to remove.
     */
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