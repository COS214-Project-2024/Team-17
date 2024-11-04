#include "BuildDecorEconomic.h"

/**
 * @class BuildDecorEconomic
 * @brief A concrete decorator that adds economic upgrades to a building.
 *
 * This class adds economic enhancements to a building, extending its functionality
 * by appending additional economic-related information to the building's display output.
 */
BuildDecorEconomic::BuildDecorEconomic(Building *b) : BuildingDecorator(b) {}

/**
 * @brief Displays information about the building, including any economic upgrades.
 *
 * This method first calls the base building's `displayBuildingInfo()` to show its 
 * original information, then appends additional details about the economic upgrade.
 */
void BuildDecorEconomic::displayBuildingInfo()
{
    if (building)
    {
        building->displayBuildingInfo();
    }
    std::cout << "This building has been upgraded with economic elements." << std::endl;
}
