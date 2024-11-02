#ifndef HOMEPAGE_CPP
#define HOMEPAGE_CPP

#include "homepage.h"
#include "./ui_homepage.h"
#include "MovingFrame.h"
#include "DraggableFrame.h"
#include "DraggableRoad.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
QVector<DraggableFrame *> buildings;
QVector<DraggableRoad *> roads;

DraggableFrame* frame;
DraggableRoad* road;
QLabel* BuildingType;

HomePage::HomePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePage)
{
    Resources::addMoney(1000000);
    Resources::addWood(1000000);
    Resources::addConcrete(1000000);
    Resources::addSteel(1000000);
    ui->setupUi(this);
    ui->frmEditBuildingPos->hide();
    ui->frmEditRoadPos->hide();
    ui->spnBuildingEditX->setMaximum(ui->scAreaMainMap->width()-120);
    ui->spnBuildingEditY->setMaximum(ui->scAreaMainMap->height()-100);
    ui->spnRoadEditX->setMaximum(ui->scAreaMainMap->width() - 100);
    ui->spnRoadEditY->setMaximum(ui->scAreaMainMap->height() - 20);
    updateInfoScreen();

    //set all build costs
    ui->spnComMallCash->setValue(BuildingRequirements::mallBuildCost);
    ui->spnComOfficeCash->setValue(BuildingRequirements::officeBuildCost);
    ui->spnComShopCash->setValue(BuildingRequirements::shopBuildCost);
    ui->spnIndFactoryCash->setValue(BuildingRequirements::factoryBuildCost);
    ui->spnIndPlantCash->setValue(BuildingRequirements::plantBuildCost);
    ui->spnIndWarehouseCash->setValue(BuildingRequirements::warehouseBuildCost);
    ui->spnLandCCenterCash->setValue(BuildingRequirements::communityCenterBuildCost);
    ui->spnLandMonumentCash->setValue(BuildingRequirements::monumentBuildCost);
    ui->spnLandParkCash->setValue(BuildingRequirements::parkBuildCost);
    ui->spnResEstateCash->setValue(BuildingRequirements::estateBuildCost);
    ui->spnResFlatCash->setValue(BuildingRequirements::flatBuildCost);
    ui->spnResHouseCash->setValue(BuildingRequirements::houseBuildCost);
    ui->spnResTownHouseCash->setValue(BuildingRequirements::townhouseBuildCost);
    ui->spnServEducationCash->setValue(BuildingRequirements::educationBuildCost);
    ui->spnServEntertainmentCash->setValue(BuildingRequirements::entertainmentBuildCost);
    ui->spnServHospitalCash->setValue(BuildingRequirements::hospitalBuildCost);
    ui->spnServSecurityCash->setValue(BuildingRequirements::securityBuildCost);
    ui->spnUtilPowerCost->setValue(BuildingRequirements::powerPlantBuildCost);
    ui->spnUtilSewageCost->setValue(BuildingRequirements::sewageSystemBuildCost);
    ui->spnUtilWasteCost->setValue(BuildingRequirements::wasteManagementBuildCost);
    ui->spnUtilWaterCost->setValue(BuildingRequirements::waterSupplyBuildCost);
    ui->spnRoadResCost->setValue(BuildingRequirements::residentialStreetBuildCost);
    ui->spnRoadMainCost->setValue(BuildingRequirements::mainRoadBuildCost);
    ui->spnRoadHighwayCost->setValue(BuildingRequirements::highwayBuildCost);

    //set all Wood costs
    ui->spnComMallWood->setValue(BuildingRequirements::mallWoodCost);
    ui->spnComOfficeWood->setValue(BuildingRequirements::officeWoodCost);
    ui->spnComShopWood->setValue(BuildingRequirements::shopWoodCost);
    ui->spnIndFactoryWood->setValue(BuildingRequirements::factoryWoodCost);
    ui->spnIndPlantWood->setValue(BuildingRequirements::plantWoodCost);
    ui->spnIndWarehouseWood->setValue(BuildingRequirements::warehouseWoodCost);
    ui->spnLandCCenterWood->setValue(BuildingRequirements::communityCenterWoodCost);
    ui->spnLandMonumentWood->setValue(BuildingRequirements::monumentWoodCost);
    ui->spnLandParkWood->setValue(BuildingRequirements::parkWoodCost);
    ui->spnResEstateWood->setValue(BuildingRequirements::estateWoodCost);
    ui->spnResFlatWood->setValue(BuildingRequirements::flatWoodCost);
    ui->spnResHouseWood->setValue(BuildingRequirements::houseWoodCost);
    ui->spnResTownHouseWood->setValue(BuildingRequirements::townhouseWoodCost);
    ui->spnServEducationWood->setValue(BuildingRequirements::educationWoodCost);
    ui->spnServEntertainmentWood->setValue(BuildingRequirements::entertainmentWoodCost);
    ui->spnServHospitalWood->setValue(BuildingRequirements::hospitalWoodCost);
    ui->spnServSecurityWood->setValue(BuildingRequirements::securityWoodCost);
    ui->spnUtilPowerWood->setValue(BuildingRequirements::powerPlantWoodCost);
    ui->spnUtilSewageWood->setValue(BuildingRequirements::sewageSystemWoodCost);
    ui->spnUtilWasteWood->setValue(BuildingRequirements::wasteManagementWoodCost);
    ui->spnUtilWaterWood->setValue(BuildingRequirements::waterSupplyWoodCost);
    ui->spnRoadResWood->setValue(BuildingRequirements::residentialStreetWoodCost);
    ui->spnRoadMainWood->setValue(BuildingRequirements::mainRoadWoodCost);
    ui->spnRoadHighwayWood->setValue(BuildingRequirements::highwayWoodCost);

    //set all concrete costs
    ui->spnComMallConcrete->setValue(BuildingRequirements::mallConcreteCost);
    ui->spnComOfficeConcrete->setValue(BuildingRequirements::officeConcreteCost);
    ui->spnComShopConcrete->setValue(BuildingRequirements::shopConcreteCost);
    ui->spnIndFactoryConcrete->setValue(BuildingRequirements::factoryConcreteCost);
    ui->spnIndPlantConcrete->setValue(BuildingRequirements::plantConcreteCost);
    ui->spnIndWarehouseConcrete->setValue(BuildingRequirements::warehouseConcreteCost);
    ui->spnLandCCenterConcrete->setValue(BuildingRequirements::communityCenterConcreteCost);
    ui->spnLandMonumentConcrete->setValue(BuildingRequirements::monumentConcreteCost);
    ui->spnLandParkConcrete->setValue(BuildingRequirements::parkConcreteCost);
    ui->spnResEstateConcrete->setValue(BuildingRequirements::estateConcreteCost);
    ui->spnResFlatConcrete->setValue(BuildingRequirements::flatConcreteCost);
    ui->spnResHouseConcrete->setValue(BuildingRequirements::houseConcreteCost);
    ui->spnResTownHouseConcrete->setValue(BuildingRequirements::townhouseConcreteCost);
    ui->spnServEducationConcrete->setValue(BuildingRequirements::educationConcreteCost);
    ui->spnServEntertainmentConcrete->setValue(BuildingRequirements::entertainmentConcreteCost);
    ui->spnServHospitalConcrete->setValue(BuildingRequirements::hospitalConcreteCost);
    ui->spnServSecurityConcrete->setValue(BuildingRequirements::securityConcreteCost);
    ui->spnUtilPowerConcrete->setValue(BuildingRequirements::powerPlantConcreteCost);
    ui->spnUtilSewageConcrete->setValue(BuildingRequirements::sewageSystemConcreteCost);
    ui->spnUtilWasteConcrete->setValue(BuildingRequirements::wasteManagementConcreteCost);
    ui->spnUtilWaterConcrete->setValue(BuildingRequirements::waterSupplyConcreteCost);
    ui->spnRoadResConcrete->setValue(BuildingRequirements::residentialStreetConcreteCost);
    ui->spnRoadMainConcrete->setValue(BuildingRequirements::mainRoadConcreteCost);
    ui->spnRoadHighwayConcrete->setValue(BuildingRequirements::highwayConcreteCost);

    //set all steel costs
    ui->spnComMallSteel->setValue(BuildingRequirements::mallSteelCost);
    ui->spnComOfficeSteel->setValue(BuildingRequirements::officeSteelCost);
    ui->spnComShopSteel->setValue(BuildingRequirements::shopSteelCost);
    ui->spnIndFactorySteel->setValue(BuildingRequirements::factorySteelCost);
    ui->spnIndPlantSteel->setValue(BuildingRequirements::plantSteelCost);
    ui->spnIndWarehouseSteel->setValue(BuildingRequirements::warehouseSteelCost);
    ui->spnLandCCenterSteel->setValue(BuildingRequirements::communityCenterSteelCost);
    ui->spnLandMonumentSteel->setValue(BuildingRequirements::monumentSteelCost);
    ui->spnLandParkSteel->setValue(BuildingRequirements::parkSteelCost);
    ui->spnResEstateSteel->setValue(BuildingRequirements::estateSteelCost);
    ui->spnResFlatSteel->setValue(BuildingRequirements::flatSteelCost);
    ui->spnResHouseSteel->setValue(BuildingRequirements::houseSteelCost);
    ui->spnResTownHouseSteel->setValue(BuildingRequirements::townhouseSteelCost);
    ui->spnServEducationSteel->setValue(BuildingRequirements::educationSteelCost);
    ui->spnServEntertainmentSteel->setValue(BuildingRequirements::entertainmentSteelCost);
    ui->spnServHospitalSteel->setValue(BuildingRequirements::hospitalSteelCost);
    ui->spnServSecuritySteel->setValue(BuildingRequirements::securitySteelCost);
    ui->spnUtilPowerSteel->setValue(BuildingRequirements::powerPlantSteelCost);
    ui->spnUtilSewageSteel->setValue(BuildingRequirements::sewageSystemSteelCost);
    ui->spnUtilWasteSteel->setValue(BuildingRequirements::wasteManagementSteelCost);
    ui->spnUtilWaterSteel->setValue(BuildingRequirements::waterSupplySteelCost);
    ui->spnRoadResSteel->setValue(BuildingRequirements::residentialStreetSteelCost);
    ui->spnRoadMainSteel->setValue(BuildingRequirements::mainRoadSteelCost);
    ui->spnRoadHighwaySteel->setValue(BuildingRequirements::highwaySteelCost);



}

HomePage::~HomePage()
{
    for (int i = 0; i < buildings.size(); i++){
        buildings[i]->setVisible(false);
        buildings[i]->deleteLater();
    }
    delete ui;
}

void HomePage::CreateBuilding(QString buildingType, Building* link)
{
    ui->spnBuildingEditX->setMaximum(ui->scAreaMainMap->width()-120);
    ui->spnBuildingEditY->setMaximum(ui->scAreaMainMap->height()-100);
    frame = new DraggableFrame(ui->scAreaMainMap, ui->spnBuildingEditX, ui->spnBuildingEditY, this);
    frame->setFrameShape(QFrame::Box);  // Optional: set frame shape
    frame->setLineWidth(2);  // Optional: set border width
    frame->setStyleSheet("background-color: red");  // Set color (using hex or color names)

    BuildingType = new QLabel(frame);
    BuildingType->setText(buildingType);
    BuildingType->setAlignment(Qt::AlignCenter);
    BuildingType->setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0);");
    BuildingType->setGeometry(0, 0, frame->width(), frame->height());
    QFont font = BuildingType->font();
    font.setPointSize(8);
    BuildingType->setFont(font);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(BuildingType);
    frame->setLayout(layout);

    BuildingType->show();

    frame->move(100, 50);
    frame->show();
    buildings.append(frame);
    ui->scAreaMainMap->addToBuildings(frame);
    ui->spnBuildingEditWidth->setValue(frame->width());
    ui->spnBuildingEditHeight->setValue(frame->height());
    ui->spnBuildingEditX->setValue(frame->x());
    ui->spnBuildingEditY->setValue(frame->y());
    ui->frmEditBuildingPos->show();
    ui->frmInfo->hide();
    ui->frmEditBuildingPos->raise();
    updateInfoScreen();
}



void HomePage::on_btnBuildBuilding_clicked()
{
    ui->frmEditBuildingPos->hide();
    ui->frmInfo->show();
    frame->editable=false;
    frame=nullptr;
    ui->tabBuildCity->setEnabled(1);
}


void HomePage::on_spnBuildingEditX_valueChanged(int arg1)
{
    if(frame!=nullptr){
        if(!frame->dragging){
            frame->move(ui->spnBuildingEditX->value(), ui->spnBuildingEditY->value());
        }
    }
}


void HomePage::on_spnBuildingEditY_valueChanged(int arg1)
{
    if(frame!=nullptr){
        if(!frame->dragging){
            frame->move(ui->spnBuildingEditX->value(), ui->spnBuildingEditY->value());
        }
    }
}


void HomePage::on_btnCancelBuilding_clicked()
{
    frame->setVisible(false);
    frame->deleteLater();
    buildings.removeOne(frame);
    ui->scAreaMainMap->removeFromBuildings(frame);
    ui->frmEditBuildingPos->hide();
    ui->frmInfo->show();
    ui->tabBuildCity->setEnabled(1);
}


void HomePage::on_spnBuildingEditWidth_valueChanged(int arg1)
{
    if(frame!=nullptr){
        frame->setFixedWidth(arg1);
        if(frame->x() + arg1 > ui->scAreaMainMap->width()){
            frame->move(ui->scAreaMainMap->width()-arg1, frame->y());
        }
        ui->spnBuildingEditX->setMaximum(ui->scAreaMainMap->width()-arg1);
    }
}


void HomePage::on_spnBuildingEditHeight_valueChanged(int arg1)
{
    if(frame!=nullptr){
        frame->setFixedHeight(arg1);
        if(frame->y() + arg1 > ui->scAreaMainMap->height()){
            frame->move(frame->x(), ui->scAreaMainMap->height()-arg1);
        }
        ui->spnBuildingEditY->setMaximum(ui->scAreaMainMap->height()-arg1);
    }
}

void HomePage::deleteBuilding(DraggableFrame* deleteMe){
    deleteMe->setVisible(false);
    buildings.removeOne(deleteMe);
    ui->scAreaMainMap->removeFromBuildings(deleteMe);
    deleteMe->deleteLater();
    ui->frmEditBuildingPos->hide();
}


void HomePage::on_cmbBuildingColor_currentIndexChanged(int index)
{
    if(frame!=nullptr){
        switch (ui->cmbBuildingColor->currentIndex()) {
            case 0:
                frame->setStyleSheet("background-color: red");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0);");
                break;
            case 1:
                frame->setStyleSheet("background-color: green");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0);");
                break;
            case 2:
                frame->setStyleSheet("background-color: blue");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0);");
                break;
            case 3:
                frame->setStyleSheet("background-color: orange");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: black; background-color: rgba(0, 0, 0, 0);");
                break;
            case 4:
                frame->setStyleSheet("background-color: yellow");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: black; background-color: rgba(0, 0, 0, 0);");
                break;
            case 5:
                frame->setStyleSheet("background-color: black");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0);");
                break;
            case 6:
                frame->setStyleSheet("background-color: white");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: black; background-color: rgba(0, 0, 0, 0);");
                break;
            case 7:
                frame->setStyleSheet("background-color: grey");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: white; background-color: rgba(0, 0, 0, 0);");
                break;
            case 8:
                frame->setStyleSheet("background-color: #fffdd0");  // Set color (using hex or color names)
                BuildingType->setStyleSheet("color: black; background-color: rgba(0, 0, 0, 0);");
                break;
        }
    }
}

void HomePage::on_btnResFlat_clicked()
{
    if(BuildingRequirements::checkResidentialRequirements("Flat")){
        FactoryBuilding *factory = new FactResidential();
        Residential *newBuilding = factory->createResBuilding("Flat");
        CreateBuilding("Flat", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Flat");
        msgBox.exec();
    }
}


void HomePage::on_btnResTownHouse_clicked()
{
    if(BuildingRequirements::checkResidentialRequirements("Townhouse")){
        FactoryBuilding *factory = new FactResidential();
        Residential *newBuilding = factory->createResBuilding("Townhouse");
        CreateBuilding("Townhouse", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Townhouse");
        msgBox.exec();
    }
}


void HomePage::on_btnResHouse_clicked()
{
    if(BuildingRequirements::checkResidentialRequirements("House")){
        FactoryBuilding *factory = new FactResidential();
        Residential *newBuilding = factory->createResBuilding("House");
        CreateBuilding("House", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build House");
        msgBox.exec();
    }
}


void HomePage::on_btnResEstate_clicked()
{
    if(BuildingRequirements::checkResidentialRequirements("Estate")){
        FactoryBuilding *factory = new FactResidential();
        Residential *newBuilding = factory->createResBuilding("Estate");
        CreateBuilding("Estate", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Estate");
        msgBox.exec();
    }
}

void HomePage::on_btnComShop_clicked()
{
    if(BuildingRequirements::checkCommercialRequirements("Shop")){
        FactoryBuilding *factory = new FactCommercial();
        Commercial *newBuilding = factory->createComBuilding("Shop");
        CreateBuilding("Shop", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Shop");
        msgBox.exec();
    }
}

void HomePage::on_btnComOffice_clicked()
{
    if(BuildingRequirements::checkCommercialRequirements("Office")){
        FactoryBuilding *factory = new FactCommercial();
        Commercial *newBuilding = factory->createComBuilding("Office");
        CreateBuilding("Office", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Office");
        msgBox.exec();
    }
}


void HomePage::on_btnComMall_clicked()
{
    if(BuildingRequirements::checkCommercialRequirements("Mall")){
        FactoryBuilding *factory = new FactCommercial();
        Commercial *newBuilding = factory->createComBuilding("Mall");
        CreateBuilding("Mall", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Mall");
        msgBox.exec();
    }
}

void HomePage::on_btnIndFactory_clicked()
{
    if(BuildingRequirements::checkIndustrialRequirements("Factory")){
        FactoryBuilding *factory = new FactIndustrial();
        Industrial *newBuilding = factory->createIndBuilding("Factory");
        CreateBuilding("Factory", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Factory");
        msgBox.exec();
    }
}


void HomePage::on_btnIndWarehouse_clicked()
{
    if(BuildingRequirements::checkIndustrialRequirements("Warehouse")){
        FactoryBuilding *factory = new FactIndustrial();
        Industrial *newBuilding = factory->createIndBuilding("Warehouse");
        CreateBuilding("Warehouse", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Warehouse");
        msgBox.exec();
    }
}


void HomePage::on_btnIndPlant_clicked()
{
    if(BuildingRequirements::checkIndustrialRequirements("Plant")){
        FactoryBuilding *factory = new FactIndustrial();
        Industrial *newBuilding = factory->createIndBuilding("Plant");
        CreateBuilding("Plant", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Plant");
        msgBox.exec();
    }
}


void HomePage::on_btnLandPark_clicked()
{
    if(BuildingRequirements::checkLandmarkRequirements("Park")){
        FactoryBuilding *factory = new FactLandmarks();
        Landmark *newBuilding = factory->createLandmark("Park");
        CreateBuilding("Park", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Park");
        msgBox.exec();
    }
}


void HomePage::on_btnLandMonument_clicked()
{
    if(BuildingRequirements::checkLandmarkRequirements("Monument")){
        FactoryBuilding *factory = new FactLandmarks();
        Landmark *newBuilding = factory->createLandmark("Monument");
        CreateBuilding("Monument", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Monument");
        msgBox.exec();
    }
}


void HomePage::on_btnLandCCenter_clicked()
{
    if(BuildingRequirements::checkLandmarkRequirements("Community Center")){
        FactoryBuilding *factory = new FactLandmarks();
        Landmark *newBuilding = factory->createLandmark("Community Center");
        CreateBuilding("Community Center", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Community Center");
        msgBox.exec();
    }
}


void HomePage::on_btnServHospital_clicked()
{
    if(BuildingRequirements::checkServiceRequirements("Hospital")){
        FactoryBuilding *factory = new FactService();
        Services *newBuilding = factory->createServiceBuilding("Hospital");
        CreateBuilding("Hospital", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Hospital");
        msgBox.exec();
    }
}


void HomePage::on_btnServEducation_clicked()
{
    if(BuildingRequirements::checkServiceRequirements("Education")){
        FactoryBuilding *factory = new FactService();
        Services *newBuilding = factory->createServiceBuilding("Education");
        CreateBuilding("Education", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Education");
        msgBox.exec();
    }
}


void HomePage::on_btnServSecurity_clicked()
{
    if(BuildingRequirements::checkServiceRequirements("Security")){
        FactoryBuilding *factory = new FactService();
        Services *newBuilding = factory->createServiceBuilding("Security");
        CreateBuilding("Security", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Security");
        msgBox.exec();
    }
}


void HomePage::on_btnServEntertainment_clicked()
{
    if(BuildingRequirements::checkServiceRequirements("Entertainment")){
        FactoryBuilding *factory = new FactService();
        Services *newBuilding = factory->createServiceBuilding("Entertainment");
        CreateBuilding("Entertainment", newBuilding);
        ui->tabBuildCity->setEnabled(0);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Not enough resources to build Entertainment");
        msgBox.exec();
    }
}


void HomePage::on_btnUtilPower_clicked()
{
    CreateBuilding("Power Station", nullptr);
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnUtilWater_clicked()
{
    CreateBuilding("Water Supply", nullptr);
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnUtilSewage_clicked()
{
    CreateBuilding("Sewage System", nullptr);
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnUtilWaste_clicked()
{
    CreateBuilding("Waste Management", nullptr);
    ui->tabBuildCity->setEnabled(0);
}

void HomePage::CreateRoad(QString roadType){
    ui->spnRoadEditX->setMaximum(ui->scAreaMainMap->width() - 120);
    ui->spnRoadEditY->setMaximum(ui->scAreaMainMap->height() - 100);
    road = new DraggableRoad(ui->scAreaMainMap, ui->spnRoadEditX, ui->spnRoadEditY, this, roads);
    road->move(100, 50);
    road->show();
    roads.append(road);
    ui->scAreaMainMap->addToRoads(road);
    ui->spnRoadEditX->setValue(road->x());
    ui->spnRoadEditY->setValue(road->y());
    ui->frmEditRoadPos->show();
    ui->frmInfo->hide();
    ui->frmEditRoadPos->raise();
}


void HomePage::on_btnRoadRes_clicked()
{
    CreateRoad("");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnBuildRoad_clicked()
{
    ui->frmEditRoadPos->hide();
    ui->frmInfo->show();
    road->editable=false;
    road=nullptr;
    ui->tabBuildCity->setEnabled(1);
}


void HomePage::on_btnCancelRoad_clicked()
{
    road->setVisible(false);
    road->deleteLater();
    roads.removeOne(road);
    ui->scAreaMainMap->removeFromRoads(road);
    ui->frmEditRoadPos->hide();
    ui->tabBuildCity->setEnabled(1);
    ui->frmInfo->show();
}


void HomePage::on_cmbRoadOrientation_currentIndexChanged(int index)
{
    if(road!=nullptr){
        if(ui->cmbRoadOrientation->currentIndex() == 0){
            road->setFixedWidth(ui->spnRoadEditLength->value());
            road->setFixedHeight(10);
        }
        else{
            road->setFixedHeight(ui->spnRoadEditLength->value());
            road->setFixedWidth(10);
        }
    }
}


void HomePage::on_spnRoadEditLength_valueChanged(int arg1)
{
    if(road!=nullptr){
        if(ui->cmbRoadOrientation->currentIndex() == 1){
            road->setFixedHeight(arg1);
        }
        else{
            road->setFixedWidth(arg1);
        }
    }
}

void HomePage::resizeEvent(QResizeEvent *event)
{
    // Call base class resize event handler
    QMainWindow::resizeEvent(event);
    // Adjust maximum values for spin boxes based on new size
    ui->spnBuildingEditX->setMaximum(ui->scAreaMainMap->width() - 120);
    ui->spnBuildingEditY->setMaximum(ui->scAreaMainMap->height() - 100);
    ui->spnRoadEditX->setMaximum(ui->scAreaMainMap->width() - 120);
    ui->spnRoadEditY->setMaximum(ui->scAreaMainMap->height() - 100);
}


void HomePage::on_spnRoadEditX_valueChanged(int arg1)
{
    if(road!=nullptr){
        if(!road->dragging){
            road->move(ui->spnRoadEditX->value(), ui->spnRoadEditY->value());
        }
    }
}


void HomePage::on_spnRoadEditY_valueChanged(int arg1)
{
    if(road!=nullptr){
        if(!road->dragging){
            road->move(ui->spnRoadEditX->value(), ui->spnRoadEditY->value());
        }
    }
}

void HomePage::updateInfoScreen()
{
    ui->dspnCash->setValue(Resources::getMoney());
    ui->spnWood->setValue(Resources::getWood());
    ui->spnConcrete->setValue(Resources::getConcrete());
    ui->spnSteel->setValue(Resources::getSteel());
}


#endif // HOMEPAGE_CPP
