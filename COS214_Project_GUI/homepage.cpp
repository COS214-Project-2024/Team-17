#include "homepage.h"
#include "./ui_homepage.h"
#include "DraggableFrame.h"
#include <QWidget>
#include <QVBoxLayout>

QVector<DraggableFrame *> buildings;

DraggableFrame* frame;
QLabel* BuildingType;

HomePage::HomePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);
    ui->frmEditBuildingPos->hide();
    ui->spnBuildingEditX->setMaximum(ui->scAreaMainMap->width()-120);
    ui->spnBuildingEditY->setMaximum(ui->scAreaMainMap->height()-100);
}

HomePage::~HomePage()
{
    for (int i = 0; i < buildings.size(); i++){
        buildings[i]->setVisible(false);
        buildings[i]->deleteLater();
    }
    delete ui;
}

void HomePage::CreateBuilding(QString buildingType)
{
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
    ui->spnBuildingEditWidth->setValue(frame->width());
    ui->spnBuildingEditHeight->setValue(frame->height());
    ui->spnBuildingEditX->setValue(frame->x());
    ui->spnBuildingEditY->setValue(frame->y());
    ui->frmEditBuildingPos->show();
    ui->frmEditBuildingPos->raise();
}



void HomePage::on_btnBuildBuilding_clicked()
{
    ui->frmEditBuildingPos->hide();
    frame->editable=false;
    ui->tabBuildCity->setEnabled(1);
}


void HomePage::on_spnBuildingEditX_valueChanged(int arg1)
{
    if(!frame->dragging){
        frame->move(ui->spnBuildingEditX->value(), ui->spnBuildingEditY->value());
    }
}


void HomePage::on_spnBuildingEditY_valueChanged(int arg1)
{
    if(!frame->dragging){
        frame->move(ui->spnBuildingEditX->value(), ui->spnBuildingEditY->value());
    }
}


void HomePage::on_btnCancelBuilding_clicked()
{
    frame->setVisible(false);
    frame->deleteLater();
    buildings.removeOne(frame);
    ui->frmEditBuildingPos->hide();
    ui->tabBuildCity->setEnabled(1);
}


void HomePage::on_spnBuildingEditWidth_valueChanged(int arg1)
{
    frame->setFixedWidth(arg1);
    if(frame->x() + arg1 > ui->scAreaMainMap->width()){
        frame->move(ui->scAreaMainMap->width()-arg1, frame->y());
    }
    ui->spnBuildingEditX->setMaximum(ui->scAreaMainMap->width()-arg1);
}


void HomePage::on_spnBuildingEditHeight_valueChanged(int arg1)
{
    frame->setFixedHeight(arg1);
    if(frame->y() + arg1 > ui->scAreaMainMap->height()){
        frame->move(frame->x(), ui->scAreaMainMap->height()-arg1);
    }
    ui->spnBuildingEditY->setMaximum(ui->scAreaMainMap->height()-arg1);
}

void HomePage::deleteBuilding(DraggableFrame* deleteMe){
    deleteMe->setVisible(false);
    buildings.removeOne(deleteMe);
    deleteMe->deleteLater();
    ui->frmEditBuildingPos->hide();
}


void HomePage::on_cmbBuildingColor_currentIndexChanged(int index)
{
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

void HomePage::on_btnResFlat_clicked()
{
    CreateBuilding("Flat");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnResTownHouse_clicked()
{
    CreateBuilding("Town House");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnResHouse_clicked()
{
    CreateBuilding("House");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnResEstate_clicked()
{
    CreateBuilding("Estate");
    ui->tabBuildCity->setEnabled(0);
}

void HomePage::on_btnComShop_clicked()
{
    CreateBuilding("Shop");
    ui->tabBuildCity->setEnabled(0);
}

void HomePage::on_btnComOffice_clicked()
{
    CreateBuilding("Office");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_spnComMall_clicked()
{
    CreateBuilding("Mall");
    ui->tabBuildCity->setEnabled(0);
}

void HomePage::on_btnIndFactory_clicked()
{
    CreateBuilding("Factory");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnIndWarehouse_clicked()
{
    CreateBuilding("Warehouse");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnIndPlant_clicked()
{
    CreateBuilding("Industrial Plant");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnLandPark_clicked()
{
    CreateBuilding("Park");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnLandMonument_clicked()
{
    CreateBuilding("Monument");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnLandCCenter_clicked()
{
    CreateBuilding("Community Center");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnServHospital_clicked()
{
    CreateBuilding("Hospital");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnServEducation_clicked()
{
    CreateBuilding("Education");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnServSecurity_clicked()
{
    CreateBuilding("Security");
    ui->tabBuildCity->setEnabled(0);
}


void HomePage::on_btnServEntertainment_clicked()
{
    CreateBuilding("Entertainment");
    ui->tabBuildCity->setEnabled(0);
}

