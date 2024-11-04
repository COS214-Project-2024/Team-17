#ifndef BUILDINGREQUIREMENTS_H
#define BUILDINGREQUIREMENTS_H

#include "../resources.h"

#include <vector>
#include <string>

using namespace std;
/**
 * @struct BuildingRequirements
 * @brief Holds building requirements and costs for different building types.
 *
 * This structure defines the costs of various resources needed to build 
 * different types of residential, commercial, industrial, landmark, 
 * service, utility, and road buildings. It also provides methods to 
 * check the building requirements for each category.
 */
struct BuildingRequirements{
    public:
        //check requirements
        static bool checkResidentialRequirements(string type);
        static bool checkCommercialRequirements(string type);
        static bool checkIndustrialRequirements(string type);
        static bool checkLandmarkRequirements(string type);
        static bool checkServiceRequirements(string type);
        static bool checkUtilityRequirements(string type);
        static bool checkRoadRequirements(string type);
        
        
        //residential
        //Flat
        static const int flatBuildCost = 1000;
        static const int flatWoodCost = 10;
        static const int flatConcreteCost = 5;
        static const int flatSteelCost = 5;
        //Townhouse
        static const int townhouseBuildCost = 1500;
        static const int townhouseWoodCost = 10;
        static const int townhouseConcreteCost = 15;
        static const int townhouseSteelCost = 10;
        //House
        static const int houseBuildCost = 2500;
        static const int houseWoodCost = 15;
        static const int houseConcreteCost = 20;
        static const int houseSteelCost = 10;
        //Estate
        static const int estateBuildCost = 4000;
        static const int estateWoodCost = 20;
        static const int estateConcreteCost = 20;
        static const int estateSteelCost = 20;

        //Commercial
        //Shop
        static const int shopBuildCost = 1000;
        static const int shopWoodCost = 5;
        static const int shopConcreteCost = 10;
        static const int shopSteelCost = 5;
        //Office
        static const int officeBuildCost = 1500;
        static const int officeWoodCost = 5;
        static const int officeConcreteCost = 10;
        static const int officeSteelCost = 5;
        //Mall
        static const int mallBuildCost = 5000;
        static const int mallWoodCost = 20;
        static const int mallConcreteCost = 25;
        static const int mallSteelCost = 25;

        //Industrial
        //Factory
        static const int factoryBuildCost = 1500;
        static const int factoryWoodCost = 20;
        static const int factoryConcreteCost = 10;
        static const int factorySteelCost = 10;
        //Warehouse
        static const int warehouseBuildCost = 1500;
        static const int warehouseWoodCost = 10;
        static const int warehouseConcreteCost = 20;
        static const int warehouseSteelCost = 10;
        //Plant
        static const int plantBuildCost = 1500;
        static const int plantWoodCost = 10;
        static const int plantConcreteCost = 10;
        static const int plantSteelCost = 20;

        //Landmark
        //Park
        static const int parkBuildCost = 1000;
        static const int parkWoodCost = 25;
        static const int parkConcreteCost = 5;
        static const int parkSteelCost = 10;
        //Monument
        static const int monumentBuildCost = 1500;
        static const int monumentWoodCost = 10;
        static const int monumentConcreteCost = 20;
        static const int monumentSteelCost = 10;
        //Community Center
        static const int communityCenterBuildCost = 2000;
        static const int communityCenterWoodCost = 20;
        static const int communityCenterConcreteCost = 30;
        static const int communityCenterSteelCost = 15;

        //Services
        //Hospital
        static const int hospitalBuildCost = 1500;
        static const int hospitalWoodCost = 5;
        static const int hospitalConcreteCost = 15;
        static const int hospitalSteelCost = 10;
        //Education
        static const int educationBuildCost = 1500;
        static const int educationWoodCost = 5;
        static const int educationConcreteCost = 15;
        static const int educationSteelCost = 10;
        //Security
        static const int securityBuildCost = 1500;
        static const int securityWoodCost = 5;
        static const int securityConcreteCost = 15;
        static const int securitySteelCost = 10;
        //Entertainment
        static const int entertainmentBuildCost = 2000;
        static const int entertainmentWoodCost = 10;
        static const int entertainmentConcreteCost = 15;
        static const int entertainmentSteelCost = 10;

        //Utility
        //Power Plant
        static const int powerPlantBuildCost = 2000;
        static const int powerPlantWoodCost = 5;
        static const int powerPlantConcreteCost = 20;
        static const int powerPlantSteelCost = 20;

        //Water Supply
        static const int waterSupplyBuildCost = 2000;
        static const int waterSupplyWoodCost = 5;
        static const int waterSupplyConcreteCost = 20;
        static const int waterSupplySteelCost = 20;

        //Waste Management
        static const int wasteManagementBuildCost = 3000;
        static const int wasteManagementWoodCost = 5;
        static const int wasteManagementConcreteCost = 30;
        static const int wasteManagementSteelCost = 10;

        //Sewage System
        static const int sewageSystemBuildCost = 3000;
        static const int sewageSystemWoodCost = 5;
        static const int sewageSystemConcreteCost = 20;
        static const int sewageSystemSteelCost = 30;

        //Road
        //Residential Street
        static const int residentialStreetBuildCost = 100;
        static const int residentialStreetWoodCost = 0;
        static const int residentialStreetConcreteCost = 5;
        static const int residentialStreetSteelCost = 0;

        //Main Road
        static const int mainRoadBuildCost = 200;
        static const int mainRoadWoodCost = 0;
        static const int mainRoadConcreteCost = 5;
        static const int mainRoadSteelCost = 5;

        //Highway
        static const int highwayBuildCost = 500;
        static const int highwayWoodCost = 0;
        static const int highwayConcreteCost = 10;
        static const int highwaySteelCost = 5;
};

#endif