#include "colours.h" // Testing colours and other includes
// BLACK IS USED FOR FUNCTION CALL CHECKS
// THINGS TO BE IGNORED AND REMOVED BEFORE FINAL DEM0

#include "./src/Buildings/FactoryBuilding.h"
#include "./src/Buildings/FactResidential.h"
#include "./src/Buildings/FactCommercial.h"
#include "./src/Buildings/FactIndustrial.h"
#include "./src/Buildings/FactLandmarks.h"
#include "./src/Buildings/FactService.h"

#include "./src/Buildings/BuildDecorUpgrade.h"
#include "./src/Buildings/BuildDecorRepair.h"
#include "./src/Buildings/BuildDecorEconomic.h"

#include "./src/Buildings/Building.h"
#include "./src/Buildings/ComMall.h"
#include "./src/Buildings/LandCCenter.h"
#include "./src/Buildings/ComOffice.h"
#include "./src/Buildings/ComShop.h"
#include "./src/Buildings/ServHospital.h"
#include "./src/Buildings/ServSecurity.h"
#include "./src/Buildings/ServEntertainment.h"
#include "./src/Buildings/LandPark.h"
#include "./src/Buildings/LandMonument.h"
#include "./src/Buildings/IndPlant.h"
#include "./src/Buildings/IndFactory.h"
#include "./src/Buildings/IndWarehouse.h"
#include "./src/Buildings/ResHouse.h"
#include "./src/Buildings/ResEstate.h"
#include "./src/Buildings/ResFlat.h"
#include "./src/Utilities/UtilPowerPlants.h"
#include "./src/Utilities/UtilWaterSupply.h"
#include "./src/Utilities/UtilWasteMan.h"
#include "./src/Utilities/UtilSewageSyst.h"

#include "./src/Citizens/CitizensIncludes.h"

#include "./src/resources.h"

// Prototypes
void test1(); // Buildings [RESIDENTIAL]
void test2(); // Buildings [COMMERCIAL]
void test3(); // Buildings [INDUSTRIAL]
void test4(); // Buildings [LANDMARKS]
void test5(); // Buildings [SERVICES]

void test6(); // Decorators [ALL]

void test7(); // Utilities [ALL]

void test8(); // Citizens [ALL]

void test9(); // Jobs [ALL]

int main()
{

    cout << YELLOW << "\t┏┓•     ┳┓  •┓ ┓      " << endl
         << "\t┃ ┓╋┓┏  ┣┫┓┏┓┃┏┫┏┓┏┓  " << endl
         << "\t┗┛┗┗┗┫  ┻┛┗┻┗┗┗┻┗ ┛   " << endl
         << "\t     ┛                 " << RESET << endl
         << endl;

    test1();
    cout << YELLOW << "==============================" << RESET << endl;
    test2();
    cout << YELLOW << "==============================" << RESET << endl;
    test3();
    cout << YELLOW << "==============================" << RESET << endl;
    test4();
    cout << YELLOW << "==============================" << RESET << endl;
    test5();
    cout << YELLOW << "==============================" << RESET << endl;
    test6();
    cout << YELLOW << "==============================" << RESET << endl;
    test7();
    cout << YELLOW << "==============================" << RESET << endl;
    test8();
    cout << YELLOW << "==============================" << RESET << endl;
    test9();
    cout << YELLOW << "==============================" << RESET << endl;

    return 0;
}

void test1()
{
    cout << YELLOW << "Test Buildings [RESIDENTIAL]" << RESET << endl;

    // House
    FactoryBuilding *factory = new FactResidential();
    Residential *building = factory->createResBuilding("House");

    building->setCapacity(5);
    building->displayBuildingInfo();
    cout << "Capacity: " << building->getCapacity() << endl;

    // Townhouse
    FactoryBuilding *factory2 = new FactResidential();
    Residential *building2 = factory2->createResBuilding("Townhouse");

    building2->setCapacity(10);
    building2->displayBuildingInfo();
    cout << "Capacity: " << building2->getCapacity() << endl;

    // Flat
    FactoryBuilding *factory3 = new FactResidential();
    Residential *building3 = factory3->createResBuilding("Flat");

    building3->setCapacity(15);
    building3->displayBuildingInfo();
    cout << "Capacity: " << building3->getCapacity() << endl;

    // Estate
    FactoryBuilding *factory4 = new FactResidential();
    Residential *building4 = factory4->createResBuilding("Estate");

    building4->setCapacity(20);
    building4->displayBuildingInfo();
    cout << "Capacity: " << building4->getCapacity() << endl;

    // Clean up
    delete building;
    delete factory;
    delete building2;
    delete factory2;
    delete building3;
    delete factory3;
    delete building4;
    delete factory4;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}

void test2()
{
    cout << YELLOW << "Test Buildings [COMMERCIAL]" << RESET << endl;

    // Mall
    FactoryBuilding *factory = new FactCommercial();
    Commercial *building = factory->createComBuilding("Mall");

    building->setJobCapacity(5);
    building->displayBuildingInfo();
    cout << "Job Capacity: " << building->getJobCapacity() << endl;

    // Shop
    FactoryBuilding *factory2 = new FactCommercial();
    Commercial *building2 = factory2->createComBuilding("Shop");

    building2->setJobCapacity(10);
    building2->displayBuildingInfo();
    cout << "Job Capacity: " << building2->getJobCapacity() << endl;

    // Office
    FactoryBuilding *factory3 = new FactCommercial();
    Commercial *building3 = factory3->createComBuilding("Office");

    building3->setJobCapacity(15);
    building3->displayBuildingInfo();
    cout << "Job Capacity: " << building3->getJobCapacity() << endl;

    // Clean up
    delete building;
    delete factory;
    delete building2;
    delete factory2;
    delete building3;
    delete factory3;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}

void test3()
{
    cout << YELLOW << "Test Buildings [INDUSTRIAL]" << RESET << endl;

    // Warehouse
    FactoryBuilding *factory = new FactIndustrial();
    Industrial *building = factory->createIndBuilding("Warehouse");

    building->setProductionCapacity(5);
    building->displayBuildingInfo();
    cout << "Production Capacity: " << building->getProductionCapacity() << endl;

    // Factory
    FactoryBuilding *factory2 = new FactIndustrial();
    Industrial *building2 = factory2->createIndBuilding("Factory");

    building2->setProductionCapacity(10);
    building2->displayBuildingInfo();
    cout << "Production Capacity: " << building2->getProductionCapacity() << endl;

    // Plant
    FactoryBuilding *factory3 = new FactIndustrial();
    Industrial *building3 = factory3->createIndBuilding("Plant");

    building3->setProductionCapacity(15);
    building3->displayBuildingInfo();
    cout << "Production Capacity: " << building3->getProductionCapacity() << endl;

    // Clean up
    delete building;
    delete factory;
    delete building2;
    delete factory2;
    delete building3;
    delete factory3;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}

void test4()
{
    cout << YELLOW << "Test Buildings [LANDMARKS]" << RESET << endl;

    // Park
    FactoryBuilding *factory = new FactLandmarks();
    Landmark *building = factory->createLandmark("Park");

    building->setVisitors(5);
    building->displayBuildingInfo();
    cout << "Visitors: " << building->getVisitors() << endl;

    // Monument
    FactoryBuilding *factory2 = new FactLandmarks();
    Landmark *building2 = factory2->createLandmark("Monument");

    building2->setVisitors(10);
    building2->displayBuildingInfo();
    cout << "Visitors: " << building2->getVisitors() << endl;

    // Community Center
    FactoryBuilding *factory3 = new FactLandmarks();
    Landmark *building3 = factory3->createLandmark("Community Center");

    building3->setVisitors(15);
    building3->displayBuildingInfo();
    cout << "Visitors: " << building3->getVisitors() << endl;

    // Clean up
    delete building;
    delete factory;
    delete building2;
    delete factory2;
    delete building3;
    delete factory3;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}

void test5()
{
    cout << YELLOW << "Test Buildings [SERVICES]" << RESET << endl;

    // Education
    FactoryBuilding *factory = new FactService();
    Services *building = factory->createServiceBuilding("Education");

    building->setVisitors(5);
    building->displayBuildingInfo();
    cout << "Visitors: " << building->getVisitors() << endl;

    // Security
    FactoryBuilding *factory2 = new FactService();
    Services *building2 = factory2->createServiceBuilding("Security");

    building2->setVisitors(10);
    building2->displayBuildingInfo();
    cout << "Visitors: " << building2->getVisitors() << endl;

    // Entertainment
    FactoryBuilding *factory3 = new FactService();
    Services *building3 = factory3->createServiceBuilding("Entertainment");

    building3->setVisitors(15);
    building3->displayBuildingInfo();
    cout << "Visitors: " << building3->getVisitors() << endl;

    // Clean up
    delete building;
    delete factory;
    delete building2;
    delete factory2;
    delete building3;
    delete factory3;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}

void test6()
{
    cout << YELLOW << "Test Decorators [ALL]" << RESET << endl;

    Building *residentialBuilding = FactResidential().createResBuilding("House");

    // Wrap the building with decorators
    residentialBuilding = new BuildDecorUpgrade(residentialBuilding);
    residentialBuilding = new BuildDecorRepair(residentialBuilding);
    residentialBuilding = new BuildDecorEconomic(residentialBuilding);

    residentialBuilding->displayBuildingInfo();

    // Upgrade
    FactoryBuilding *factory = new FactResidential();
    Residential *building = factory->createResBuilding("House");

    BuildingDecorator *upgrade = new BuildDecorUpgrade(building);
    upgrade->displayBuildingInfo();

    // Repair
    BuildingDecorator *repair = new BuildDecorRepair(building);
    repair->displayBuildingInfo();

    // Economic
    BuildingDecorator *economic = new BuildDecorEconomic(building);
    economic->displayBuildingInfo();

    // Clean up
    delete building;
    delete factory;

    // delete residentialBuilding;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}

void test7()
{
    cout << YELLOW << "Test Utilities [ALL]" << RESET << endl;

    // Create a commercial
    ComMall *mall = new ComMall();
    ComOffice *office = new ComOffice();
    ComShop *shop = new ComShop();
    mall->displayBuildingInfo();
    cout << "Mall building type:" << mall->getBuildingType() << endl;

    UtilPowerPlants *powerPlant = new UtilPowerPlants();
    UtilWaterSupply *waterPlant = new UtilWaterSupply();
    UtilWasteMan *wastePlant = new UtilWasteMan();
    UtilSewageSyst *sewagePlant = new UtilSewageSyst();
    mall->addUtility(powerPlant);
    office->addUtility(waterPlant);
    shop->addUtility(wastePlant);
    mall->addUtility(sewagePlant);

    ComMall *mall1 = new ComMall();
    mall1->addUtility(powerPlant);
    cout << "Built?" << endl;
    cout << "Power Plant state:" << powerPlant->isOperational() << endl;
    cout << endl;
    cout << "Mall state:" << mall1->getState() << endl;
    cout << "Power Plant state:" << powerPlant->isOperational() << endl;
    mall1->setState(true);
    // mall1->setState(false);
    cout << endl;
    cout << "States after set true" << endl;
    cout << "Mall state:" << mall1->getState() << endl;
    cout << "Power Plant state:" << powerPlant->isOperational() << endl;

    cout << endl;
    mall1->setState(false);
    cout << "States after set false from true" << endl;
    cout << "Mall state:" << mall1->getState() << endl;
    cout << "Power Plant state:" << powerPlant->isOperational() << endl;
    cout << endl;
    // mall->notifyUtilities();
    mall->removeUtility(powerPlant);
    mall->removeUtility(sewagePlant);
    office->removeUtility(waterPlant);
    shop->removeUtility(wastePlant);

    cout << endl;
    cout << "END OF COMMERCIAL TESTING!" << endl;
    cout << endl;
    // create service
    ServHospital *hospital = new ServHospital();
    ServSecurity *security = new ServSecurity();
    ServEntertainment *entertainment = new ServEntertainment();

    UtilPowerPlants *SpowerPlant = new UtilPowerPlants();
    UtilWaterSupply *SwaterPlant = new UtilWaterSupply();
    UtilWasteMan *SwastePlant = new UtilWasteMan();
    UtilSewageSyst *SsewagePlant = new UtilSewageSyst();

    hospital->addUtility(SpowerPlant);
    security->addUtility(SwaterPlant);
    entertainment->addUtility(SwastePlant);
    hospital->addUtility(SsewagePlant);

    ComMall *hospital1 = new ComMall();
    hospital1->addUtility(SpowerPlant);
    cout << "Built?" << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;
    cout << endl;
    cout << "Mall state:" << hospital1->getState() << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;
    hospital1->setState(true);
    // mall1->setState(false);
    cout << endl;
    cout << "States after set true" << endl;
    cout << "Mall state:" << hospital1->getState() << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;

    cout << endl;
    hospital1->setState(false);
    cout << "States after set false from true" << endl;
    cout << "Mall state:" << hospital1->getState() << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;
    cout << endl;
    // mall->notifyUtilities();
    hospital->removeUtility(SpowerPlant);
    hospital->removeUtility(SsewagePlant);
    security->removeUtility(SwaterPlant);
    entertainment->removeUtility(SwastePlant);

    cout << endl;

    cout << endl;
    cout << "END OF SERVICE TESTING!" << endl;
    cout << endl;

    // create landmark
    LandPark *park = new LandPark();
    LandCCenter *land = new LandCCenter();
    LandMonument *landmonument = new LandMonument();

    park->addUtility(SpowerPlant);
    land->addUtility(SwaterPlant);
    landmonument->addUtility(SwastePlant);
    park->addUtility(SsewagePlant);

    LandMonument *hospital11 = new LandMonument();
    hospital11->addUtility(SpowerPlant);
    cout << "Built?" << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;
    cout << endl;
    cout << "Mall state:" << hospital11->getState() << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;
    hospital1->setState(true);
    // mall1->setState(false);
    cout << endl;
    cout << "States after set true" << endl;
    cout << "Mall state:" << hospital11->getState() << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;

    cout << endl;
    hospital1->setState(false);
    cout << "States after set false from true" << endl;
    cout << "Mall state:" << hospital11->getState() << endl;
    cout << "Power Plant state:" << SpowerPlant->isOperational() << endl;
    cout << endl;
    // mall->notifyUtilities();
    hospital1->removeUtility(SpowerPlant);
    hospital11->removeUtility(SpowerPlant);
    hospital->removeUtility(SsewagePlant);
    security->removeUtility(SwaterPlant);
    entertainment->removeUtility(SwastePlant);

    cout << endl;
    cout << "END OF LANDMARK TESTING!" << endl;
    cout << endl;
    // Create Industry
    IndPlant *plant = new IndPlant();
    IndFactory *factory = new IndFactory();
    IndWarehouse *warehouse = new IndWarehouse();

    UtilPowerPlants *IpowerPlant = new UtilPowerPlants();
    UtilWaterSupply *IwaterPlant = new UtilWaterSupply();
    UtilWasteMan *IwastePlant = new UtilWasteMan();
    UtilSewageSyst *IsewagePlant = new UtilSewageSyst();
    // Industry linking testing
    plant->addUtility(IsewagePlant);
    factory->addUtility(IpowerPlant);
    warehouse->addUtility(IwaterPlant);
    cout << endl;
    plant->displayBuildingInfo();
    cout << endl;

    plant->getState();
    factory->getState();
    cout << endl;

    plant->setState(false);
    cout << "Plant state after setting true:" << plant->getState() << endl;
    cout << "Utility attached state:" << IsewagePlant->isOperational() << endl;

    factory->setState(true);
    cout << "Factory state after setting true:" << factory->getState() << endl;
    cout << "Utility attached state:" << IpowerPlant->isOperational() << endl;

    plant->removeUtility(IsewagePlant);
    factory->removeUtility(IpowerPlant);
    warehouse->removeUtility(IwaterPlant);

    cout << "END OF INDUSTRY TESTING!" << endl;
    cout << endl;

    // Create Ressidence
    ResHouse *house = new ResHouse();
    ResEstate *estate = new ResEstate();
    ResFlat *flat = new ResFlat();

    // Creating utilities
    UtilPowerPlants *RpowerPlant = new UtilPowerPlants();
    UtilWaterSupply *RwaterPlant = new UtilWaterSupply();
    UtilWasteMan *RwastePlant = new UtilWasteMan();
    UtilSewageSyst *RsewagePlant = new UtilSewageSyst();

    // Ressidence linking testing
    house->addUtility(wastePlant);
    estate->addUtility(powerPlant);
    flat->addUtility(waterPlant);

    cout << endl;
    house->displayBuildingInfo();
    estate->displayBuildingInfo();
    flat->displayBuildingInfo();
    cout << endl;

    house->getState();
    estate->getState();
    cout << endl;
    house->setState(false);
    cout << "Hose state after setting true:" << house->getState() << endl;
    cout << "Utility attached state:" << wastePlant->isOperational() << endl;

    estate->setState(true);
    cout << "Estate state after setting true:" << estate->getState() << endl;
    cout << "Utility attached state:" << powerPlant->isOperational() << endl;

    house->removeUtility(wastePlant);
    estate->removeUtility(powerPlant);
    flat->removeUtility(waterPlant);

    cout << "END OF RESIDENCE TESTING!" << endl;
    cout << endl;

    delete mall;
    delete office;
    delete shop;
    delete security;
    delete entertainment;
    delete hospital;
    delete park;
    delete land;
    delete landmonument;
    delete plant;
    delete factory;
    delete warehouse;
    delete house;
    delete estate;
    delete flat;
    delete powerPlant;
    delete waterPlant;
    delete wastePlant;
    delete sewagePlant;
    delete SpowerPlant;
    delete SwaterPlant;
    delete SwastePlant;
    delete SsewagePlant;
    delete IpowerPlant;
    delete IwaterPlant;
    delete IwastePlant;
    delete IsewagePlant;
    delete RpowerPlant;
    delete RwaterPlant;
    delete RwastePlant;
    delete RsewagePlant;
    cout << "END OF PROGRAM!" << endl;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}

void test8()
{

    std::cout << "############################################" << std::endl;
    std::cout << "Testing Citizens" << std::endl;
    std::cout << "############################################" << std::endl;
    CityMediator *mediator = CityCentralMediator::getInstance();
    Citizen *citizen = new Citizen();
    std::cout << " - Citizen " << citizen->getName() << " created" << std::endl;
    std::cout << " - Testing Citizen State" << std::endl;
    citizen->setState(new Happy());
    citizen->setState(new Content());
    citizen->setState(new Indifferent());
    citizen->setState(new Discontent());
    citizen->setState(new Upset());
    std::cout << " - Testing notifyChange" << std::endl;
    UtilPowerPlants *powerPlant = new UtilPowerPlants();
    ResEstate *building = new ResEstate();
    mediator->registerBuilding(building);
    mediator->registerUtility(powerPlant);
    mediator->notifyUtilityChange(powerPlant, false, "Test Message");
    
    // cout << "Citizen Count: " << Resources::getMaxPopulation() <<endl;
    // cout << "wood" << Resources::getWood()<< endl;
    // cout << "steel" << Resources::getSteel()<< endl;
    // cout << "concrete" << Resources::getConcrete()<< endl;

    // cout << "electricity" << Resources::getElectricityUsage()<< endl;
    // cout << "water" << Resources::getWaterUsage()<< endl;

    std::cout << " - Testing Complete!" << std::endl;
    


    delete citizen;
    delete mediator;
}

void test9()
{
    std::cout << "############################################" << std::endl;
    std::cout << "Testing Jobs" << std::endl;
    std::cout << "############################################" << std::endl;
    Citizen *citizen = new Citizen();
    
    ComMall *mall = new ComMall();
    mall->addEmployee(citizen);
    std::cout << " - Testing Jobs" << std::endl;
    citizen->getWorkplace()->displayBuildingInfo();
    mall->removeEmployee(citizen);
    if(citizen->getWorkplace() == nullptr){
        std::cout << " - Citizen is unemployed" << std::endl;
    }
    else{
        std::cout << " - Citizen is employed" << std::endl;
    }

    std::cout << " - Testing Complete!" << std::endl;
    delete mall;
    delete citizen;
}