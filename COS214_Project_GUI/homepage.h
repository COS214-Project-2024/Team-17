#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
class DraggableFrame;
class DraggableRoad;
#include "../src/Buildings/BuildingRequirements.h"
#include "../src/resources.h"

#include "../src/Buildings/FactResidential.h"
#include "../src/Buildings/FactCommercial.h"
#include "../src/Buildings/FactIndustrial.h"
#include "../src/Buildings/FactLandmarks.h"
#include "../src/Buildings/FactService.h"
#include "../src/Buildings/Building.h"
#include "../src/Transport/TransportInclude.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class HomePage;
}
QT_END_NAMESPACE

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);
    void deleteBuilding(DraggableFrame* deleteMe);
    void deleteRoad(DraggableRoad* deleteMe);
    ~HomePage();
    Ui::HomePage *ui;
    void CreateBuilding(QString buildingType, Building* link);
    void CreateRoad(QString roadType, RoadComponent *link);
    void updateInfoScreen();

    void resizeEvent(QResizeEvent *event);
    QVector<DraggableFrame*> getBuildings();
    QVector<DraggableRoad*> getRoads();

private slots:

    void on_btnCancelBuilding_clicked();

    void on_spnBuildingEditX_valueChanged(int arg1);

    void on_spnBuildingEditY_valueChanged(int arg1);

    void on_spnBuildingEditWidth_valueChanged(int arg1);

    void on_spnBuildingEditHeight_valueChanged(int arg1);

    void on_cmbBuildingColor_currentIndexChanged(int index);

    void on_btnBuildBuilding_clicked();

    void on_btnResFlat_clicked();

    void on_btnResTownHouse_clicked();

    void on_btnResHouse_clicked();

    void on_btnResEstate_clicked();

    void on_btnComShop_clicked();

    void on_btnComOffice_clicked();

    void on_btnComMall_clicked();

    void on_btnIndFactory_clicked();

    void on_btnIndWarehouse_clicked();

    void on_btnIndPlant_clicked();

    void on_btnLandPark_clicked();

    void on_btnLandMonument_clicked();

    void on_btnLandCCenter_clicked();

    void on_btnServHospital_clicked();

    void on_btnServEducation_clicked();

    void on_btnServSecurity_clicked();

    void on_btnServEntertainment_clicked();

    void on_btnUtilPower_clicked();

    void on_btnUtilWater_clicked();

    void on_btnUtilSewage_clicked();

    void on_btnUtilWaste_clicked();

    void on_btnBuildRoad_clicked();

    void on_btnCancelRoad_clicked();

    void on_cmbRoadOrientation_currentIndexChanged(int index);

    void on_spnRoadEditLength_valueChanged(int arg1);

    void on_spnRoadEditX_valueChanged(int arg1);

    void on_spnRoadEditY_valueChanged(int arg1);

    void on_btnRoadRes_clicked();

    void on_btnRoadMain_clicked();

    void on_btnRoadHighway_clicked();

private:


};
#endif // HOMEPAGE_H
