cmake_minimum_required(VERSION 3.5)

project(COS214_Project_GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Concurrent)

set(PROJECT_SOURCES
        main.cpp
        homepage.cpp
        homepage.h
        homepage.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(COS214_Project_GUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        DraggableFrame.h
        DraggableRoad.h
        214Resources.qrc
        MovingFrame.h
        MovingFrame.cpp
        DraggableRoad.cpp
        DraggableFrame.cpp
        textbrowserstream.h textbrowserstream.cpp
        ../src/Buildings/BuildDecorEconomic.cpp ../src/Buildings/BuildDecorEconomic.h ../src/Buildings/BuildDecorRepair.cpp ../src/Buildings/BuildDecorRepair.h ../src/Buildings/BuildDecorUpgrade.cpp ../src/Buildings/BuildDecorUpgrade.h ../src/Buildings/Building.cpp ../src/Buildings/Building.h ../src/Buildings/BuildingDecorator.cpp ../src/Buildings/BuildingDecorator.h ../src/Buildings/BuildingRequirements.cpp ../src/Buildings/BuildingRequirements.h ../src/Buildings/ComMall.cpp ../src/Buildings/ComMall.h ../src/Buildings/Commercial.cpp ../src/Buildings/Commercial.h ../src/Buildings/ComOffice.cpp ../src/Buildings/ComOffice.h ../src/Buildings/ComShop.cpp ../src/Buildings/ComShop.h ../src/Buildings/FactCommercial.cpp ../src/Buildings/FactCommercial.h ../src/Buildings/FactIndustrial.cpp ../src/Buildings/FactIndustrial.h ../src/Buildings/FactLandmarks.cpp ../src/Buildings/FactLandmarks.h ../src/Buildings/FactoryBuilding.h ../src/Buildings/FactResidential.cpp ../src/Buildings/FactResidential.h ../src/Buildings/FactService.cpp ../src/Buildings/FactService.h ../src/Buildings/IndFactory.cpp ../src/Buildings/IndFactory.h ../src/Buildings/IndPlant.cpp ../src/Buildings/IndPlant.h ../src/Buildings/Industrial.cpp ../src/Buildings/Industrial.h ../src/Buildings/IndWarehouse.cpp ../src/Buildings/IndWarehouse.h ../src/Buildings/LandCCenter.cpp ../src/Buildings/LandCCenter.h ../src/Buildings/LandMark.cpp ../src/Buildings/Landmark.h ../src/Buildings/LandMonument.cpp ../src/Buildings/LandMonument.h ../src/Buildings/LandPark.cpp ../src/Buildings/LandPark.h ../src/Buildings/ResEstate.cpp ../src/Buildings/ResEstate.h ../src/Buildings/ResFlat.cpp ../src/Buildings/ResFlat.h ../src/Buildings/ResHouse.cpp ../src/Buildings/ResHouse.h ../src/Buildings/Residential.cpp ../src/Buildings/Residential.h ../src/Buildings/ResTownhouse.cpp ../src/Buildings/ResTownhouse.h ../src/Buildings/ServEducation.cpp ../src/Buildings/ServEducation.h ../src/Buildings/ServEntertainment.cpp ../src/Buildings/ServEntertainment.h ../src/Buildings/ServHospital.cpp ../src/Buildings/ServHospital.h ../src/Buildings/Services.cpp ../src/Buildings/Services.h ../src/Buildings/ServSecurity.cpp ../src/Buildings/ServSecurity.h ../src/Citizens/CitizenStates/CitizenStatesIncludes.h ../src/Citizens/CitizenStates/Content.cpp ../src/Citizens/CitizenStates/Content.h ../src/Citizens/CitizenStates/Discontent.cpp ../src/Citizens/CitizenStates/Discontent.h ../src/Citizens/CitizenStates/Happy.cpp ../src/Citizens/CitizenStates/Happy.h ../src/Citizens/CitizenStates/Indifferent.cpp ../src/Citizens/CitizenStates/Indifferent.h ../src/Citizens/CitizenStates/Upset.cpp ../src/Citizens/CitizenStates/Upset.h ../src/Citizens/Bus.cpp ../src/Citizens/Bus.h ../src/Citizens/Citizen.cpp ../src/Citizens/Citizen.h ../src/Citizens/CitizenNameGen.cpp ../src/Citizens/CitizenNameGen.h ../src/Citizens/CitizensIncludes.h ../src/Citizens/CitizenState.h ../src/Citizens/CityBlock.cpp ../src/Citizens/CityBlock.h ../src/Citizens/CityCentralMediator.cpp ../src/Citizens/CityCentralMediator.h ../src/Citizens/CityMediator.h ../src/Citizens/first-names.txt ../src/Citizens/last-names.txt ../src/Government+Tax/AllocateTaxCommand.cpp ../src/Government+Tax/AllocateTaxCommand.h ../src/Government+Tax/BudgetPolicy.h ../src/Government+Tax/CitizenTaxAB.cpp ../src/Government+Tax/CitizenTaxAB.h ../src/Government+Tax/CityStructure.cpp ../src/Government+Tax/CityStructure.h ../src/Government+Tax/CollectTaxCommand.cpp ../src/Government+Tax/CollectTaxCommand.h ../src/Government+Tax/Government.cpp ../src/Government+Tax/Government.h ../src/Government+Tax/HealthPolicy.cpp ../src/Government+Tax/HealthPolicy.h ../src/Government+Tax/InfrastructureBudgetPolicy.cpp ../src/Government+Tax/InfrastructureBudgetPolicy.h ../src/Government+Tax/InfrastructurePolicy.cpp ../src/Government+Tax/InfrastructurePolicy.h ../src/Government+Tax/Law.h ../src/Government+Tax/Policy.h ../src/Government+Tax/SetTaxRateCommand.cpp ../src/Government+Tax/SetTaxRateCommand.h ../src/Government+Tax/TaxAllocationHandler.cpp ../src/Government+Tax/TaxAllocationHandler.h ../src/Government+Tax/TaxAndBudgetVisitor.h ../src/Government+Tax/TaxCollectionHandler.cpp ../src/Government+Tax/TaxCollectionHandler.h ../src/Government+Tax/TaxCommand.h ../src/Government+Tax/TaxHandler.cpp ../src/Government+Tax/TaxHandler.h ../src/Government+Tax/TaxManager.cpp ../src/Government+Tax/TaxManager.h ../src/Government+Tax/TaxRateHandler.cpp ../src/Government+Tax/TaxRateHandler.h ../src/Transport/RoadComponentTypes/Highways.cpp ../src/Transport/RoadComponentTypes/Highways.h ../src/Transport/RoadComponentTypes/MainRoads.cpp ../src/Transport/RoadComponentTypes/MainRoads.h ../src/Transport/RoadComponentTypes/ResidentialStreets.cpp ../src/Transport/RoadComponentTypes/ResidentialStreets.h ../src/Transport/RoadComponentTypes/RoadComponentTypesIncludes.h ../src/Transport/RoadComponentTypes/RoadsComposite.cpp ../src/Transport/RoadComponentTypes/RoadsComposite.h ../src/Transport/RoadIterators/RoadIteratorCon.cpp ../src/Transport/RoadIterators/RoadIteratorCon.h ../src/Transport/RoadIterators/RoadIteratorsIncludes.h ../src/Transport/RoadStates/Congested.cpp ../src/Transport/RoadStates/Congested.h ../src/Transport/RoadStates/RoadStatesIncludes.h ../src/Transport/RoadStates/UnderConstruction.cpp ../src/Transport/RoadStates/UnderConstruction.h ../src/Transport/RoadStates/WorkingNoIssues.cpp ../src/Transport/RoadStates/WorkingNoIssues.h ../src/Transport/readme.txt ../src/Transport/RoadComponent.cpp ../src/Transport/RoadComponent.h ../src/Transport/RoadIterator.h ../src/Transport/RoadState.h ../src/Transport/Trainstation.cpp ../src/Transport/Trainstation.h ../src/Transport/TransportInclude.h ../src/Utilities/UtilityManager.cpp ../src/Utilities/UtilityManager.h ../src/Utilities/UtilPowerPlants.cpp ../src/Utilities/UtilPowerPlants.h ../src/Utilities/UtilSewageSyst.cpp ../src/Utilities/UtilSewageSyst.h ../src/Utilities/UtilWasteMan.cpp ../src/Utilities/UtilWasteMan.h ../src/Utilities/UtilWaterSupplly.cpp ../src/Utilities/UtilWaterSupply.h ../src/Game.cpp ../src/Game.h ../src/Policy.cpp ../src/Policy.h ../src/resources.cpp ../src/resources.h





    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET COS214_Project_GUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(COS214_Project_GUI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(COS214_Project_GUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(COS214_Project_GUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Concurrent)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.COS214_Project_GUI)
endif()
set_target_properties(COS214_Project_GUI PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS COS214_Project_GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(COS214_Project_GUI)
endif()
