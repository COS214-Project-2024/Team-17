#include "BuildDecorEconomic.h"

BuildDecorEconomic::BuildDecorEconomic(Building* b) : BuildingDecorator(b) {}

void BuildDecorEconomic::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    cout << "This building has been upgraded with economic elements." << endl;
}