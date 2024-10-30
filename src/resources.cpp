#include "resources.h"

Resources::Resources(){
    woodUnits = 0;
    steelUnits = 0;
    concreteUnits = 0;
    electricityUnits = 0;
    waterUnits = 0;
    money = 0;
    maxPopulation = 0;
    currentPopulation = 0;
}

Resources::~Resources(){
    woodUnits = 0;
    steelUnits = 0;
    concreteUnits = 0;
    electricityUnits = 0;
    waterUnits = 0;
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

int Resources::getElectricity(){
    return electricityUnits;
}

int Resources::getWater(){
    return waterUnits;
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

void Resources::addElectricity(int electricity){
    electricityUnits += electricity;
}

void Resources::addWater(int water){
    waterUnits += water;
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

void Resources::removeElectricity(int electricity){
    electricityUnits -= electricity;
}

void Resources::removeWater(int water){
    waterUnits -= water;
}

void Resources::removeMoney(double money){
    this->money -= money;
}

void Resources::removePopulation(int population){
    currentPopulation -= population;
}