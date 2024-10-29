#include <iostream>
#include "../Buildings/Building.h"
#include "../Buildings/ComMall.h"
#include "UtilPowerPlants.h"
#include "UtilWaterSupply.h"
#include "UtilWasteMan.h"
#include "UtilSewageSyst.h"
#include "../Buildings/LandCCenter.h"
#include "../Buildings/ComOffice.h"
#include "../Buildings/ComShop.h"
#include "../Buildings/ServHospital.h"
#include "../Buildings/ServSecurity.h"
#include "../Buildings/ServEntertainment.h"
#include "../Buildings/LandPark.h"
#include "../Buildings/LandMonument.h"
#include "../Buildings/IndPlant.h"
#include "../Buildings/IndFactory.h"
#include "../Buildings/IndWarehouse.h"
#include "../Buildings/ResHouse.h"
#include "../Buildings/ResEstate.h"
#include "../Buildings/ResFlat.h"

int main() {//Building needs to be updates to fix inheritance and abstraction!
    // Create a commercial
    ComMall mall;
    ComOffice office;
    ComShop shop;

    // create service
    ServHospital hospital;
    ServSecurity security;
    ServEntertainment entertainment;

    // create landmark
    LandPark park;
    LandCCenter land;
    LandMonument landmonument;

    //Create Industry
    IndPlant plant;
    IndFactory factory;
    IndWarehouse warehouse;

    // Create Ressidence
    ResHouse house;
    ResEstate estate;
    ResFlat flat;

    //Creating utilities
     UtilPowerPlants* powerPlant = new UtilPowerPlants();
     UtilWaterSupply* waterPlant = new UtilWaterSupply();
     UtilWasteMan* wastePlant = new UtilWasteMan();    
     UtilSewageSyst* sewagePlant = new UtilSewageSyst();
    
cout << endl;
    // Comercial linking testing
    mall.addUtility(powerPlant);
    office.addUtility(waterPlant);
    shop.addUtility(wastePlant);
cout << endl;
    // Service linking testing
    security.addUtility(sewagePlant);
    entertainment.addUtility(powerPlant);
    hospital.addUtility(waterPlant);
cout << endl;
    // Landmark linking testing
    park.addUtility(wastePlant);
    land.addUtility(powerPlant);
    landmonument.addUtility(waterPlant);
cout << endl;
    // Industry linking testing
    plant.addUtility(sewagePlant);
    factory.addUtility(powerPlant);
    warehouse.addUtility(waterPlant);
cout << endl;

    // Ressidence linking testing
    house.addUtility(wastePlant);
    estate.addUtility(powerPlant);
    flat.addUtility(waterPlant);

    cout << endl;

    // Display initial state
    mall.displayBuildingInfo();
    office.displayBuildingInfo();
    shop.displayBuildingInfo();
    security.displayBuildingInfo();
    entertainment.displayBuildingInfo();
    hospital.displayBuildingInfo();
    park.displayBuildingInfo();
    land.displayBuildingInfo();
    landmonument.displayBuildingInfo();
    plant.displayBuildingInfo();
    factory.displayBuildingInfo();
    warehouse.displayBuildingInfo();
    house.displayBuildingInfo();
    estate.displayBuildingInfo();
    flat.displayBuildingInfo();
    cout << endl;
    std::cout << "Mall type: " << mall.getBuildingType() << std::endl;
    std::cout << "Office type: " << office.getBuildingType() << std::endl;
    std::cout << "Shop type: " << shop.getBuildingType() << std::endl;
    std::cout << "Security type: " << security.getBuildingType() << std::endl;
    std::cout << "Entertainment type: " << entertainment.getBuildingType() << std::endl;
    std::cout << "Hospital type: " << hospital.getBuildingType() << std::endl;
    std::cout << "Park type: " << park.getBuildingType() << std::endl;
    std::cout << "Land type: " << land.getBuildingType() << std::endl;
    std::cout << "Landmonument type: " << landmonument.getBuildingType() << std::endl;
    std::cout << "Plant type: " << plant.getBuildingType() << std::endl;
    std::cout << "Factory type: " << factory.getBuildingType() << std::endl;
    std::cout << "Warehouse type: " << warehouse.getBuildingType() << std::endl;
    std::cout << "House type: " << house.getBuildingType() << std::endl;
    std::cout << "Estate type: " << estate.getBuildingType() << std::endl;
    std::cout << "Flat type: " << flat.getBuildingType() << std::endl;
    cout << endl;
    std::cout << "Mall operational state: " << std::boolalpha << mall.getState() << std::endl;
    std::cout << "Office operational state: " << std::boolalpha << office.getState() << std::endl;
    std::cout << "Shop operational state: " << std::boolalpha << shop.getState() << std::endl;
    std::cout << "Security operational state: " << std::boolalpha << security.getState() << std::endl;
    std::cout << "Entertainment operational state: " << std::boolalpha << entertainment.getState() << std::endl;
    std::cout << "Hospital operational state: " << std::boolalpha << hospital.getState() << std::endl;
    std::cout << "Park operational state: " << std::boolalpha << park.getState() << std::endl;
    std::cout << "Land operational state: " << std::boolalpha << land.getState() << std::endl;
    std::cout << "Landmonument operational state: " << std::boolalpha << landmonument.getState() << std::endl;
    std::cout << "Plant operational state: " << std::boolalpha << plant.getState() << std::endl;
    std::cout << "Factory operational state: " << std::boolalpha << factory.getState() << std::endl;
    std::cout << "Warehouse operational state: " << std::boolalpha << warehouse.getState() << std::endl;
    std::cout << "House operational state: " << std::boolalpha << house.getState() << std::endl;
    std::cout << "Estate operational state: " << std::boolalpha << estate.getState() << std::endl;
    std::cout << "Flat operational state: " << std::boolalpha << flat.getState() << std::endl;
    cout << endl;


    // Start the power plant utility
    // powerPlant->startUtility();
    std::cout << "Power plant operational state: " << std::boolalpha << powerPlant->isOperational() << std::endl;
    std::cout << "Water plant operational state: " << std::boolalpha << waterPlant->isOperational() << std::endl;
    std::cout << "Waste plant operational state: " << std::boolalpha << wastePlant->isOperational() << std::endl;
    std::cout << "Sewage plant operational state: " << std::boolalpha << sewagePlant->isOperational() << std::endl;
    cout << endl;


    // Change the state of the mall to operational, triggering utilities
    mall.setState(true);
    std::cout << "Power plant operational state: " << std::boolalpha << powerPlant->isOperational() << std::endl;

    // Notify utilities to respond to the mall's state change
    mall.callUtilities();
    office.callUtilities();
    std::cout << "waterPlant operational state: " << std::boolalpha << waterPlant->isOperational() << std::endl;
    std::cout<< "Shop state:"<<shop.getState()<<std::endl;

    // Shutdown the power plant
    powerPlant->shutDown();
    cout << "State:"<<powerPlant->isOperational() << endl;
    // Clean up
    mall.removeUtility(powerPlant);
    office.removeUtility(waterPlant);
    shop.removeUtility(wastePlant);
    security.removeUtility(sewagePlant);
    entertainment.removeUtility(powerPlant);
    hospital.removeUtility(waterPlant);
    park.removeUtility(wastePlant);
    land.removeUtility(powerPlant);
    landmonument.removeUtility(waterPlant);
    plant.removeUtility(sewagePlant);
    factory.removeUtility(powerPlant);
    warehouse.removeUtility(waterPlant);
    house.removeUtility(wastePlant);
    estate.removeUtility(powerPlant);
    flat.removeUtility(waterPlant);

    delete powerPlant;
    delete waterPlant;
    delete wastePlant;
    delete sewagePlant;

    cout << "End of program" << endl;




    // land.addUtility(new UtilPowerPlants());
    // land.getBuildingType();
    // land.getState();
    // // land.setState(true);
    // land.callUtilities();
    // mall.setJobCapacity(150);
    // cout << "GAP" << endl;
    // // Create a utility (power plant) and attach it to the mall
    // UtilPowerPlants* powerPlant = new UtilPowerPlants();
    // mall.addUtility(powerPlant);

    // // Display initial state
    // mall.displayBuildingInfo();
    // std::cout << "Mall type: " << mall.getBuildingType() << std::endl;
    // std::cout << "Mall operational state: " << std::boolalpha << mall.getState() << std::endl;

    // // Start the power plant utility
    // powerPlant->startUtility();
    // std::cout << "Power plant operational state: " << std::boolalpha << powerPlant->isOperational() << std::endl;

    // // Change the state of the mall to operational, triggering utilities
    // mall.setState(true);

    // // Notify utilities to respond to the mall's state change
    // mall.callUtilities();

    // // Shutdown the power plant
    // powerPlant->shutDown();
    // cout << "State:"<<powerPlant->isOperational() << endl;
    // // Clean up
    // mall.removeUtility(powerPlant);
    // land.removeUtility(powerPlant);
    
    // delete powerPlant;


    // cout << "End of program" << endl;
    


    return 0;
}
