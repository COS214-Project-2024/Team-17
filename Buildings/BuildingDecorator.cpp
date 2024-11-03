#include "BuildingDecorator.h"

BuildingDecorator::BuildingDecorator(Building* b) : building(b) {}

void BuildingDecorator::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
}

BuildingDecorator::~BuildingDecorator() {
    delete building;
}