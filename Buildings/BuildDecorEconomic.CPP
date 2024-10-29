#include "BuildDecorEconomic.h"

BuildDecorEconomic::BuildDecorEconomic(Building* b) : BuildingDecorator(b) {}

void BuildDecorEconomic::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    cout << "This building has been decorated with economic elements." << endl;
}