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
#include "networking.h"
#include "SerialPortSelect.h"
//#include "database/DataDaemon.h"
#include "targetlist.h"
#include "MapSymbol22.h"
#include "Waypoint22.h"
#include "Vehicle22.h"
#include "vehicle_list.h"
#include "consolelog.h"
#include "vehicleelementdisplay.h"

//GUI Testing headers
#include "telemetrygui.h"
#include "waypointgui.h"
#include "vehicleauthorizationgui.h"
#include "ugv_state.h"
#include "uavpayload.h"
#include "targetinggui.h"
#include "vehicleinfo.h"
#include "MainWindowADI.h"

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

    //Initialize Connect funtions for network
    void initNetworkingConnects();

    //Initialize database
   // void initDatabase();

    double getLatitude();
    double getLongitude();

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
    targetingGUI* targeting;

    ConsoleLog* consolelog;
    VehicleInfo* vInfo;


    QPushButton command;
    QWidget commandLayoutWidget;
    QWidget controlLayoutWidget;
    QPushButton control;
    QGridLayout lowerBar;
    QWidget lowerBarWidget;
    QGridLayout command_box;
    QGridLayout command_control;
    //DUMMY PLACEHOLDERS
    //QPushButton vehicleList;
    //VehicleElementDiplay vehicleList;
    QGridLayout *vehicleList;
    VehicleElementDisplay *element;
    std::vector<VehicleElementDisplay*> *elementList;
    MainWindowADI *attitude;

    //Networking
    networking *network;
    NodeQueue* vUpdate;

    //Database
    //DataDaemon* database;

    vehicle_list *vList22;
    Vehicle22 *v1251, *v35, *v46, *v69, *v103, *v101, *v102;

    QPushButton* sendcmd;
    QPushButton* ugvDrop;

    //Dynamic Vehicle addition
    void addVehicle(int,int);

    bool commandShow;
    bool controlShow;

    //Temp, remove when MainwindowADI has a slot to take in the vech to display
    int currentVech;
private slots:
    void update_vehicle_queue();
    void update_targets(Target*);
    void mapReady();
    void vStatus(int, int);
    //for uav drop
    void UDrop();
    void UGVDrop();

    void showCommand();
    void showControl();

    //Test Slot for new signal
    void updateVech(int);

    //Target
    void addTarget(float lat, float lon);
    //void addWaypoint(int,Waypoint22*);
//    void removeTarget(int gID);

    //Test
    void elementSelect(int);
    void updateADI(int);

signals:
    void update_vehicle(int vehicle);
    void updateIDGraphic(int gID, EsriRuntimeQt::Graphic *graphic);
    void removeLayerGraphic(int gID);
    //for uav drop
    void drop(int);
};

#endif // MAINWINDOW_H
