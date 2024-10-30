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

bool BuildingDecorator::checkBuildRequirements() {
    return building->checkBuildRequirements();
}

bool BuildingDecorator::getState() {
    return building->getState();
}