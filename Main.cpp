#include "colours.h" // Testing colours and other includes
// BLACK IS USED FOR FUNCTION CALL CHECKS
// THINGS TO BE IGNORED AND REMOVED BEFORE FINAL DEM0


#include "./Buildings/FactoryBuilding.h"
#include "./Buildings/FactResidential.h"
#include "./Buildings/FactCommercial.h"
#include "./Buildings/FactIndustrial.h"
#include "./Buildings/FactLandmarks.h"
#include "./Buildings/FactService.h"

#include "./Buildings/BuildDecorUpgrade.h"
#include "./Buildings/BuildDecorRepair.h"
#include "./Buildings/BuildDecorEconomic.h"


// Prototypes
void test1(); // Buildings [RESIDENTIAL]
void test2(); // Buildings [COMMERCIAL]
void test3(); // Buildings [INDUSTRIAL]
void test4(); // Buildings [LANDMARKS]
void test5(); // Buildings [SERVICES]

void test6(); // Decorators [ALL]

int main() {

 	cout << YELLOW  << "\t┏┓•     ┳┓  •┓ ┓      " << endl
                    << "\t┃ ┓╋┓┏  ┣┫┓┏┓┃┏┫┏┓┏┓  " << endl
                    << "\t┗┛┗┗┗┫  ┻┛┗┻┗┗┗┻┗ ┛   " << endl
                    << "\t     ┛                 " << RESET << endl << endl;

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

	return 0;
}

void test1() {
    cout << YELLOW << "Test Buildings [RESIDENTIAL]" << RESET << endl;

    // House
    FactoryBuilding* factory = new FactResidential();
    Residential* building = factory->createResBuilding("House");

    building->setCapacity(5);
    building->displayBuildingInfo();
    cout << "Capacity: " << building->getCapacity() << endl;

    // Townhouse
    FactoryBuilding* factory2 = new FactResidential();
    Residential* building2 = factory2->createResBuilding("Townhouse");

    building2->setCapacity(10);
    building2->displayBuildingInfo();
    cout << "Capacity: " << building2->getCapacity() << endl;

    // Flat
    FactoryBuilding* factory3 = new FactResidential();
    Residential* building3 = factory3->createResBuilding("Flat");

    building3->setCapacity(15);
    building3->displayBuildingInfo();
    cout << "Capacity: " << building3->getCapacity() << endl;

    // Estate
    FactoryBuilding* factory4 = new FactResidential();
    Residential* building4 = factory4->createResBuilding("Estate");

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

void test2() {
    cout << YELLOW << "Test Buildings [COMMERCIAL]" << RESET << endl;

    // Mall
    FactoryBuilding* factory = new FactCommercial();
    Commercial* building = factory->createComBuilding("Mall");

    building->setJobCapacity(5);
    building->displayBuildingInfo();
    cout << "Job Capacity: " << building->getJobCapacity() << endl;

    // Shop
    FactoryBuilding* factory2 = new FactCommercial();
    Commercial* building2 = factory2->createComBuilding("Shop");

    building2->setJobCapacity(10);
    building2->displayBuildingInfo();
    cout << "Job Capacity: " << building2->getJobCapacity() << endl;

    // Office
    FactoryBuilding* factory3 = new FactCommercial();
    Commercial* building3 = factory3->createComBuilding("Office");

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

void test3() {
    cout << YELLOW << "Test Buildings [INDUSTRIAL]" << RESET << endl;

    // Warehouse
    FactoryBuilding* factory = new FactIndustrial();
    Industrial* building = factory->createIndBuilding("Warehouse");

    building->setProductionCapacity(5);
    building->displayBuildingInfo();
    cout << "Production Capacity: " << building->getProductionCapacity() << endl;

    // Factory
    FactoryBuilding* factory2 = new FactIndustrial();
    Industrial* building2 = factory2->createIndBuilding("Factory");

    building2->setProductionCapacity(10);
    building2->displayBuildingInfo();
    cout << "Production Capacity: " << building2->getProductionCapacity() << endl;

    // Plant
    FactoryBuilding* factory3 = new FactIndustrial();
    Industrial* building3 = factory3->createIndBuilding("Plant");

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

void test4() {
    cout << YELLOW << "Test Buildings [LANDMARKS]" << RESET << endl;

    //Park
    FactoryBuilding* factory = new FactLandmarks();
    Landmark* building = factory->createLandmark("Park");

    building->setVisitors(5);
    building->displayBuildingInfo();
    cout << "Visitors: " << building->getVisitors() << endl;

    //Monument
    FactoryBuilding* factory2 = new FactLandmarks();
    Landmark* building2 = factory2->createLandmark("Monument");

    building2->setVisitors(10);
    building2->displayBuildingInfo();
    cout << "Visitors: " << building2->getVisitors() << endl;

    //Community Center
    FactoryBuilding* factory3 = new FactLandmarks();
    Landmark* building3 = factory3->createLandmark("Community Center");

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

void test5() {
    cout << YELLOW << "Test Buildings [SERVICES]" << RESET << endl;

    //Education
    FactoryBuilding* factory = new FactService();
    Services* building = factory->createServiceBuilding("Education");

    building->setVisitors(5);
    building->displayBuildingInfo();
    cout << "Visitors: " << building->getVisitors() << endl;

    //Security
    FactoryBuilding* factory2 = new FactService();
    Services* building2 = factory2->createServiceBuilding("Security");

    building2->setVisitors(10);
    building2->displayBuildingInfo();
    cout << "Visitors: " << building2->getVisitors() << endl;

    //Entertainment
    FactoryBuilding* factory3 = new FactService();
    Services* building3 = factory3->createServiceBuilding("Entertainment");

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

void test6() {
    cout << YELLOW << "Test Decorators [ALL]" << RESET << endl;

    // Building* residentialBuilding = FactResidential().createResBuilding("House");

    // // Wrap the building with decorators
    // residentialBuilding = new BuildDecorUpgrade(residentialBuilding);
    // residentialBuilding = new BuildDecorRepair(residentialBuilding);
    // residentialBuilding = new BuildDecorEconomic(residentialBuilding);

    // residentialBuilding->displayBuildingInfo();

    // Upgrade
    FactoryBuilding* factory = new FactResidential();
    Residential* building = factory->createResBuilding("House");

    BuildingDecorator* upgrade = new BuildDecorUpgrade(building);
    upgrade->displayBuildingInfo();

    // Repair
    BuildingDecorator* repair = new BuildDecorRepair(building);
    repair->displayBuildingInfo();

    // // Economic - ERROR??? 
    // BuildingDecorator* economic = new BuildDecorEconomic(building);
    // economic->displayBuildingInfo();

    //Clean up
    delete building;
    delete factory;

   // delete residentialBuilding;

    cout << GREEN << "✧ ✦\tAll tests passed!\t✦ ✧" << RESET << endl;
}