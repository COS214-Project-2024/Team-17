#include "BuildDecorUpgrade.h"

BuildDecorUpgrade::BuildDecorUpgrade(Building* b) : BuildingDecorator(b) {}

void BuildDecorUpgrade::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    cout << "This building has been decorated with upgrades." << endl;
}