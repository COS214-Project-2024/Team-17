#include "BuildDecorRepair.h"

BuildDecorRepair::BuildDecorRepair(Building* b) : BuildingDecorator(b) {}

void BuildDecorRepair::displayBuildingInfo() {
    if (building) {
        building->displayBuildingInfo();
    }
    cout << "This building has been decorated with repairs." << endl;
}