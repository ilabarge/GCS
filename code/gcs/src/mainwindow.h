#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt headers
#include <QtWidgets>
#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QQueue>
#include <QLineEdit>
#include <QTableView>
#include <QApplication>
#include <QList>

//ArcGIS headers
#include <ArcGISTiledMapServiceLayer.h>
#include <MapGraphicsView.h>
#include <Polyline.h>
#include <Graphic.h>

//Our headers
#include "MapView.h"
#include "sidebar.h"
#include "gcs_toolbar.h"
//#include "networking.h"
#include "SerialPortSelect.h"
#include "database/DataDaemon.h"
#include "targetlist.h"
#include "MapSymbol22.h"
#include "Waypoint22.h"
#include "Vehicle22.h"
#include "vehicle_list.h"
#include "consolelog.h"

//GUI Testing headers
#include "telemetrygui.h"
#include "waypointgui.h"
#include "vehicleauthorizationgui.h"
#include "ugv_state.h"
#include "uavpayload.h"
#include "targetinggui.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();

    //Initialize the map
    void initMap();

    //Initialize the widgets
    void initWidgets();

    //Initialize networking
    void initNetworking();

    //Initialize database
    void initDatabase();

    //Widgets
    QPushButton* quitButton;
    MapView* mv;

    //Register key presses
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);

private:
    QGridLayout* mainLayout;

    //Toolbars
    sideBar* sb;
    GcsToolbar *mtb;
    SerialPortSelect* serialSelect;
    TargetList* targetList;

    //Test GUI
    QPushButton *UGV_JOYSTICK;
    QPushButton *UGV_JOYSTICKSTOP;
    TelemetryGUI *Telemetry;
    WaypointGUI *way;
    VehicleAuthorizationGUI *Authorize;
    UGV_state* UGV_States;
    UAVPayload* UAV_Payload;
    QLabel* CPPuavStatusLabel;
    QLabel* SLOuavStatusLabel;
    QLabel* uavModeLabel;
    targetingGUI* targeting;

    ConsoleLog* consolelog;
    //Networking
    //networking *network;
    //NodeQueue* vUpdate;

    //Database
    DataDaemon* database;

    vehicle_list *vList22;
    Waypoint22 *w22, *w23, *w24;
    Vehicle22 *v46, *v69, *v2, *v101, *v102;

    QPushButton* sendcmd;
    QPushButton* ugvDrop;

    //Dynamic Vehicle addition
    void addVehicle(int,int);

private slots:
    void update_vehicle_queue();
    void update_targets(Target*);
    void mapReady();
    void vStatus(int, int);
    //for uav drop
    void UDrop();
    void UGVDrop();

    //Test Slot for new signal
    void updateVech(int);

    //Target
    void addTarget(float lat, float lon);
    //void addWaypoint(int,Waypoint22*);
//    void removeTarget(int gID);

signals:
    void update_vehicle(int vehicle);
    void updateIDGraphic(int gID, EsriRuntimeQt::Graphic *graphic);
    void removeLayerGraphic(int gID);
    //for uav drop
    void drop(int);
};

#endif // MAINWINDOW_H
