#include "resources.h"

Resources::Resources(){
    woodUnits = 0;
    steelUnits = 0;
    concreteUnits = 0;
    totalElectricityUnitUsage = 0;
    totalElectricityUnitGenerated = 0;
    waterUnitsGenerated = 0;
    waterUnitsUsed = 0;
    money = 0;
    maxPopulation = 0;
    currentPopulation = 0;
}

Resources::~Resources(){
    woodUnits = 0;
    steelUnits = 0;
    concreteUnits = 0;
    totalElectricityUnitUsage = 0;
    waterUnitsGenerated = 0;
    waterUnitsUsed = 0;
    money = 0;
    maxPopulation = 0;
    currentPopulation = 0;
}

int Resources::getWood(){
    return woodUnits;
}

int Resources::getSteel(){
    return steelUnits;
}

int Resources::getConcrete(){
    return concreteUnits;
}

int Resources::getElectricityUsage(){
    return totalElectricityUnitUsage;
}

int Resources::getElectricityGenerated(){
    return totalElectricityUnitGenerated;
}

int Resources::getWaterUsage(){
    return waterUnitsUsed;
}

int Resources::getWaterGenerated(){
    return waterUnitsGenerated;
}

double Resources::getMoney(){
    return money;
}

int Resources::getPopulation(){
    return currentPopulation;
}

void Resources::addWood(int wood){
    woodUnits += wood;
}

void Resources::addSteel(int steel){
    steelUnits += steel;
}

void Resources::addConcrete(int concrete){
    concreteUnits += concrete;
}

void Resources::addElectricityGenerated(int electricity){
    totalElectricityUnitGenerated += electricity;
}

void Resources::addElectricityUsage(int electricity){
    totalElectricityUnitUsage += electricity;
}

void Resources::addWaterGenerated(int water){
    waterUnitsGenerated += water;
}

void Resources::addWaterUsage(int water){
    waterUnitsUsed += water;
}

void Resources::addMoney(double money){
    this->money += money;
}

void Resources::addPopulation(int population){
    currentPopulation += population;
}

void Resources::addToMaxPopulation(int population){
    maxPopulation += population;
}

void Resources::removeWood(int wood){
    woodUnits -= wood;
}

void Resources::removeSteel(int steel){
    steelUnits -= steel;
}

void Resources::removeConcrete(int concrete){
    concreteUnits -= concrete;
}

void Resources::removeElectricityGenerated(int electricity){
    totalElectricityUnitGenerated -= electricity;
}

void Resources::removeElectricityUsage(int electricity){
    totalElectricityUnitUsage -= electricity;
}

void Resources::removeWaterGenerated(int water){
    waterUnitsGenerated -= water;
}

void Resources::removeWaterUsage(int water){
    waterUnitsUsed -= water;
}

void Resources::removeMoney(double money){
    this->money -= money;
}

void Resources::removePopulation(int population){
    currentPopulation -= population;
}