#include "BuildingRequirements.h"

bool BuildingRequirements::checkResidentialRequirements(string type){
    if(type == "Flat"){
        if(Resources::getMoney() >= flatBuildCost && Resources::getWood() >= flatWoodCost && Resources::getConcrete() >= flatConcreteCost && Resources::getSteel() >= flatSteelCost){
            return true;
        }
    }
    else if(type == "Townhouse"){
        if(Resources::getMoney() >= townhouseBuildCost && Resources::getWood() >= townhouseWoodCost && Resources::getConcrete() >= townhouseConcreteCost && Resources::getSteel() >= townhouseSteelCost){
            return true;
        }
    }
    else if(type == "House"){
        if(Resources::getMoney() >= houseBuildCost && Resources::getWood() >= houseWoodCost && Resources::getConcrete() >= houseConcreteCost && Resources::getSteel() >= houseSteelCost){
            return true;
        }
    }
    else if(type == "Estate"){
        if(Resources::getMoney() >= estateBuildCost && Resources::getWood() >= estateWoodCost && Resources::getConcrete() >= estateConcreteCost && Resources::getSteel() >= estateSteelCost){
            return true;
        }
    }
    return false;
}

bool BuildingRequirements::checkCommercialRequirements(string type){
    if(type == "Shop"){
        if(Resources::getMoney() >= shopBuildCost && Resources::getWood() >= shopWoodCost && Resources::getConcrete() >= shopConcreteCost && Resources::getSteel() >= shopSteelCost){
            return true;
        }
    }
    else if(type == "Office"){
        if(Resources::getMoney() >= officeBuildCost && Resources::getWood() >= officeWoodCost && Resources::getConcrete() >= officeConcreteCost && Resources::getSteel() >= officeSteelCost){
            return true;
        }
    }
    else if(type == "Mall"){
        if(Resources::getMoney() >= mallBuildCost && Resources::getWood() >= mallWoodCost && Resources::getConcrete() >= mallConcreteCost && Resources::getSteel() >= mallSteelCost){
            return true;
        }
    }
    return false;
}

bool BuildingRequirements::checkIndustrialRequirements(string type){
    if(type == "Factory"){
        if(Resources::getMoney() >= factoryBuildCost && Resources::getWood() >= factoryWoodCost && Resources::getConcrete() >= factoryConcreteCost && Resources::getSteel() >= factorySteelCost){
            return true;
        }
    }
    else if(type == "Plant"){
        if(Resources::getMoney() >= plantBuildCost && Resources::getWood() >= plantWoodCost && Resources::getConcrete() >= plantConcreteCost && Resources::getSteel() >= plantSteelCost){
            return true;
        }
    }
    else if(type == "Warehouse"){
        if(Resources::getMoney() >= warehouseBuildCost && Resources::getWood() >= warehouseWoodCost && Resources::getConcrete() >= warehouseConcreteCost && Resources::getSteel() >= warehouseSteelCost){
            return true;
        }
    }
    return false;
}

bool BuildingRequirements::checkLandmarkRequirements(string type){
    if(type == "Park"){
        if(Resources::getMoney() >= parkBuildCost && Resources::getWood() >= parkWoodCost && Resources::getConcrete() >= parkConcreteCost && Resources::getSteel() >= parkSteelCost){
            return true;
        }
    }
    else if(type == "Monument"){
        if(Resources::getMoney() >= monumentBuildCost && Resources::getWood() >= monumentWoodCost && Resources::getConcrete() >= monumentConcreteCost && Resources::getSteel() >= monumentSteelCost){
            return true;
        }
    }
    else if(type == "CommunityCenter"){
        if(Resources::getMoney() >= communityCenterBuildCost && Resources::getWood() >= communityCenterWoodCost && Resources::getConcrete() >= communityCenterConcreteCost && Resources::getSteel() >= communityCenterSteelCost){
            return true;
        }
    } 
    return false;
}

bool BuildingRequirements::checkServiceRequirements(string type){
    if(type == "Hospital"){
        if(Resources::getMoney() >= hospitalBuildCost && Resources::getWood() >= hospitalWoodCost && Resources::getConcrete() >= hospitalConcreteCost && Resources::getSteel() >= hospitalSteelCost){
            return true;
        }
    }
    else if(type == "Education"){
        if(Resources::getMoney() >= educationBuildCost && Resources::getWood() >= educationWoodCost && Resources::getConcrete() >= educationConcreteCost && Resources::getSteel() >= educationSteelCost){
            return true;
        }
    }
    else if(type == "Security"){
        if(Resources::getMoney() >= securityBuildCost && Resources::getWood() >= securityWoodCost && Resources::getConcrete() >= securityConcreteCost && Resources::getSteel() >= securitySteelCost){
            return true;
        }
    }
    else if (type == "Entertainment"){
        if(Resources::getMoney() >= entertainmentBuildCost && Resources::getWood() >= entertainmentWoodCost && Resources::getConcrete() >= entertainmentConcreteCost && Resources::getSteel() >= entertainmentSteelCost){
            return true;
        }
    }
    return false;
}

bool BuildingRequirements::checkUtilityRequirements(string type){
    if(type == "PowerPlant"){
        if(Resources::getMoney() >= powerPlantBuildCost && Resources::getWood() >= powerPlantWoodCost && Resources::getConcrete() >= powerPlantConcreteCost && Resources::getSteel() >= powerPlantSteelCost){
            return true;
        }
    }
    else if(type == "WaterSupply"){
        if(Resources::getMoney() >= waterSupplyBuildCost && Resources::getWood() >= waterSupplyWoodCost && Resources::getConcrete() >= waterSupplyConcreteCost && Resources::getSteel() >= waterSupplySteelCost){
            return true;
        }
    }
    else if(type == "WasteManagement"){
        if(Resources::getMoney() >= wasteManagementBuildCost && Resources::getWood() >= wasteManagementWoodCost && Resources::getConcrete() >= wasteManagementConcreteCost && Resources::getSteel() >= wasteManagementSteelCost){
            return true;
        }
    }
    else if(type == "SewageSystem"){
        if(Resources::getMoney() >= sewageSystemBuildCost && Resources::getWood() >= sewageSystemWoodCost && Resources::getConcrete() >= sewageSystemConcreteCost && Resources::getSteel() >= sewageSystemSteelCost){
            return true;
        }
    }
    return false;
}