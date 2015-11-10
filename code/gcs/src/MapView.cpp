// Copyright 2013 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

//ArcGIS Headers
namespace EsriRuntimeQt
{
class MapGraphicsView;
class Map;
class ArcGISLocalTiledLayer;
class ArcGISTiledMapServiceLayer;
class ArcGISDynamicMapServiceLayer;
class ArcGISFeatureLayer;
class GraphicsLayer;
class FeatureLayer;
}
#include "ArcGISRuntime.h"

#include <MapGraphicsView.h>

//Our Headers
#include "MapView.h"

// Uncomment if needed
//#include "ServiceInfoTask.h"

MapView::MapView(QWidget* parent)
{
    //Set to openGL rendering
    //EsriRuntimeQt::ArcGISRuntime::setRenderEngine(EsriRuntimeQt::RenderEngine::OpenGL);
    m_map = new EsriRuntimeQt::Map(this);
    m_mapGraphicsView = EsriRuntimeQt::MapGraphicsView::create(m_map, this);
    m_map->setWrapAroundEnabled(false);
    //m_map->setEsriLogoVisible(false);

    connect(m_map,SIGNAL(mapReady()), this, SLOT(onMapReady()));
    connect(m_map, SIGNAL(mousePress(QMouseEvent&)), this, SLOT(onMousePress(QMouseEvent&)));

    if(it.isConnected()){
        qDebug() << "Internet present";
        //// ArcGIS Online Tiled Basemap Layer
        m_tiledServiceLayer = new EsriRuntimeQt::ArcGISTiledMapServiceLayer("http://services.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer", this);
        m_map->addLayer(m_tiledServiceLayer);
        imageryLayer = new EsriRuntimeQt::ArcGISTiledMapServiceLayer("http://services.arcgisonline.com/ArcGIS/rest/services/NatGeo_World_Map/MapServer", this);
        m_map->addLayer(imageryLayer);
    }
    else{
        qDebug() << "No internet";
        //// Local Tiled Basemap Layer using: sdk/samples/data/tpks/Topographic.tpk
        QString path = EsriRuntimeQt::ArcGISRuntime::installDirectory();
        path.append("/sdk/samples/data");
        qDebug() << "Path: " << path;
        QDir dataDir(path); // using QDir to convert to correct file separator
        QString pathSampleData = dataDir.path() + QDir::separator();
        qDebug() << "path sample : " << pathSampleData;
        QString tiledBaseMapLayer = pathSampleData + "tpks" + QDir::separator() + "Topographic.tpk";
        qDebug() << "tiled base layer " << tiledBaseMapLayer;
        m_tiledLayer =  new EsriRuntimeQt::ArcGISLocalTiledLayer(tiledBaseMapLayer, this);
        m_map->addLayer(m_tiledLayer);
    }

//    Note for points:
//          Top-left : -2.0037508342787E7,2.0037508342787E7
//          Center   : 0,0
    grLayer = new GCSGraphicsLayer();
    targetLayer = new GCSGraphicsLayer();
    uavLayer = new GCSGraphicsLayer();
    ugvLayer = new GCSGraphicsLayer();
    waypointLayer = new GCSGraphicsLayer();
    opspaceLayer = new GCSGraphicsLayer();
    satelliteLayer = new GCSGraphicsLayer();


    m_map->addLayer(grLayer);
    m_map->addLayer(targetLayer);
    m_map->addLayer(uavLayer);
    m_map->addLayer(ugvLayer);
    m_map->addLayer(waypointLayer);
    m_map->addLayer(opspaceLayer);
    m_map->addLayer(satelliteLayer);

    //// ArcGIS Online Dynamic Map Service Layer
    //m_dynamicServiceLayer = EsriRuntimeQt::ArcGISDynamicMapServiceLayer("http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Specialty/ESRI_StateCityHighway_USA/MapServer");
    //m_map->addLayer(m_dynamicServiceLayer);

    //Local Dynamic Layer using: sdk/samples/data/mpks/USCitiesStates.mpk
    /*
    QString dataPath = pathSampleData + "mpks" + QDir::separator() + "USCitiesStates.mpk";
    m_localMapService = EsriRuntimeQt::LocalMapService(dataPath);

    // connect to signal that is emitted when the service is created successfully
    connect(&m_localMapService, SIGNAL(serviceCreationSuccess(const QString&, const QString&)), this, SLOT(onLocalServiceCreationSuccess(const QString&, const QString&)));

    // connect to signal that is emitted when the service failed
    connect(&m_localMapService, SIGNAL(serviceCreationFailure(const QString&)), this, SLOT(onLocalServiceCreationFailure(const QString&)));

    // start the service and the Local Server
    m_localMapService.start();
    */

    // Feature service using: sdk/samples/data/mpks/USCitiesStates.mpk
    /*
    QString localFeatureService = pathSampleData + "mpks" + QDir::separator() + "USCitiesStates.mpk";
    m_localFeatureService = EsriRuntimeQt::LocalFeatureService(localFeatureService);
    m_localFeatureService.setMaximumRecords(3000);

    // connect to signal that is emitted when the service is created successfully
    connect(&m_localFeatureService, SIGNAL(serviceCreationSuccess(const QString&, const QString&)), this, SLOT(onFeatureServiceCreationSuccess(const QString&, const QString&)));

    // connect to signal that is emitted when the service failed
    connect(&m_localFeatureService, SIGNAL(serviceCreationFailure(const QString&)), this, SLOT(onFeatureServiceCreationFailure(const QString&)));

    // start the service and the Local Server
    m_localFeatureService.start();
    */

    // Graphics Layer
    /*
    EsriRuntimeQt::Point point1(0, 0);
    EsriRuntimeQt::SimpleMarkerSymbol redCircle(Qt::red, 8, EsriRuntimeQt::SimpleMarkerSymbolStyle::Circle);
    EsriRuntimeQt::Graphic graphic1(point1, redCircle);
    m_graphicsLayer.addGraphic(graphic1);
    m_map->addLayer(m_graphicsLayer);
    */

    // Feature Layer
    /*
    //Specify the URL to create a Service Info Task to get a specific layer by name or id
    EsriRuntimeQt::ServiceInfoTask serviceTaskInfo("http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Demographics/ESRI_Census_USA/MapServer/");
    EsriRuntimeQt::FeatureServiceInfo featureServiceInfo = serviceTaskInfo.createFeatureServiceInfo();
    QList<EsriRuntimeQt::FeatureLayerInfo> layerInfoList= featureServiceInfo.layers("states");

    if(layerInfoList.size() > 0 && !layerInfoList.at(0).url().isEmpty())
    {
        //Layer can also be created directly by specifying the layer in the url
        m_featureLayer = EsriRuntimeQt::ArcGISFeatureLayer(layerInfoList.at(0).url());
        m_map->addLayer(m_featureLayer);
    }
    */

    //// connect to signal that is emitted when the map is ready
    connect(m_map, SIGNAL(mapReady()), this, SLOT(onMapReady()));
}

void MapView::UAVLayerVisible(bool visible){
    uavLayer->setVisible(visible);
}

void MapView::UGVLayerVisible(bool visible){
    ugvLayer->setVisible(visible);
}

void MapView::waypointLayerVisible(bool visible){
    waypointLayer->setVisible(visible);
}

void MapView::zoneLayerVisible(bool visible){
    opspaceLayer->setVisible(visible);
}

void MapView::targetLayerVisible(bool visible){
    targetLayer->setVisible(visible);
}

void MapView::satelliteLayerVisible(bool visible){
    satelliteLayer->setVisible(visible);
}

MapView::~MapView()
{
    // stop the Local Map Service
    /*
  if(m_localMapService.status() == EsriRuntimeQt::LocalServiceStatus::Running)
     m_localMapService.stopAndWait();
  */

    // stop the Local Feature Service
    /*
  if(m_localFeatureService.status() == EsriRuntimeQt::LocalServiceStatus::Running)
    m_localFeatureService.stopAndWait();
  */

    // stop the Local Server Instance for local service
    /*
  if (EsriRuntimeQt::LocalServer::instance().isRunning())
    EsriRuntimeQt::LocalServer::instance().shutdownAndWait();
  */

    //// disconnect signals for Local Map Service
    //disconnect(&m_localMapService, SIGNAL(serviceCreationSuccess(const QString&, const QString&)), this, SLOT(onLocalServiceCreationSuccess(const QString&, const QString&)));
    //disconnect(&m_localMapService, SIGNAL(serviceCreationFailure(const QString&)), this, SLOT(onLocalServiceCreationFailure(const QString&)));

    //// disconnect signals for Feature Service
    //disconnect(&m_localFeatureService, SIGNAL(serviceCreationSuccess(const QString&, const QString&)), this, SLOT(onFeatureServiceCreationSuccess(const QString&, const QString&)));
    //disconnect(&m_localFeatureService, SIGNAL(serviceCreationFailure(const QString&)), this, SLOT(onFeatureServiceCreationFailure(const QString&)));

    // disconnect signal for Map
    disconnect(m_map, SIGNAL(mapReady()), this, SLOT(onMapReady()));
    delete m_mapGraphicsView;
}

/*
void MapView::onLocalServiceCreationSuccess(const QString& url, const QString& name)
{
  Q_UNUSED(url);
  Q_UNUSED(name);

   // create the ArcGISDynamicMapServiceLayer using the LocalMapService's url
   m_dynamicLocalServiceLayer = EsriRuntimeQt::ArcGISDynamicMapServiceLayer(m_localMapService.urlMapService());
   m_map->addLayer(m_dynamicLocalServiceLayer);
}
*/

/*
void MapView::onLocalServiceCreationFailure(const QString& name)
{
  qWarning() << name + " failed to start";
  qWarning() << m_localMapService.error().what();
}
*/

/*
void MapView::onFeatureServiceCreationSuccess(const QString& url, const QString& name)
{
  Q_UNUSED(url);
  Q_UNUSED(name);

  QString serviceUrl;
  EsriRuntimeQt::FeatureServiceInfo featureServiceInfo = m_localFeatureService.featureServiceInfo();
  QList<EsriRuntimeQt::FeatureLayerInfo> layerInfoList= featureServiceInfo.layers("Cities");

  if(layerInfoList.size() > 0)
    serviceUrl = layerInfoList.at(0).url();

  if (serviceUrl.isEmpty())
  {
    qWarning() << "The required layer does not exist";
    return;
  }

  m_localFeatureLayer = EsriRuntimeQt::ArcGISFeatureLayer(serviceUrl);
  m_map->addLayer(m_localFeatureLayer);
}
*/

/*
void MapView::onFeatureServiceCreationFailure(const QString& name)
{
  qWarning() << name + " failed to start";
  qWarning() << m_localFeatureService.error().what();
}
*/

void MapView::onMapReady(){
    spatialRef = m_map->spatialReference();
    //m_map->addLayer(grLayer);
    qDebug() << "Map Ready.";
    emit MapReady();
}

bool MapView::moveVehicleGraphic(Vehicle22& vehicle, const EsriRuntimeQt::Point point){
    grLayer->moveGraphic(vehicle.getGraphicID(), point);
    return true;
}

bool MapView::moveVehicleGraphic(Vehicle22& vehicle, double lat, double lon){
    grLayer->moveGraphic(vehicle.getGraphicID(), decimalDegreesToPoint(lat,lon));
    return true;
}

bool MapView::moveLayerGraphic(Layers layer, EsriRuntimeQt::Graphic& graphic, const EsriRuntimeQt::Point p){
    //TODO: Add behavior
    //ESRI update 10.2.5 change uid to uniqueId
    switch(layer){
        case UGV:
            ugvLayer->moveGraphic(graphic.uniqueId(), p);
            break;
        case UAV:
            uavLayer->moveGraphic(graphic.uniqueId(), p);
            break;
        case TARGET:
            targetLayer->moveGraphic(graphic.uniqueId(), p);
            break;
        case SATELLITE:
            satelliteLayer->moveGraphic(graphic.uniqueId(), p);
            break;
        case WAYPOINT:
            waypointLayer->moveGraphic(graphic.uniqueId(), p);
            break;
        case ZONE:
            opspaceLayer->moveGraphic(graphic.uniqueId(), p);
            break;
        default:
            break;
    }

    grLayer->moveGraphic(graphic.uniqueId(), p);
    return true;
}

bool MapView::moveLayerGraphic(Layers layer, EsriRuntimeQt::Graphic& graphic, double lat, double lon){
    //TODO: Add behavior
    grLayer->moveGraphic(graphic.uniqueId(), decimalDegreesToPoint(lat,lon));
    return true;
}

//bool MapView::addGraphicToLayer(EsriRuntimeQt::GraphicsLayer& layer, EsriRuntimeQt::Graphic& graphic){
bool MapView::addGraphicToLayer(EsriRuntimeQt::Graphic *graphic){
    //layer.addGraphic(graphic);
    grLayer->addGraphic(graphic);
    return true;
}

EsriRuntimeQt::Point MapView::decimalDegreesToPoint(QString coordinates){
    return EsriRuntimeQt::CoordinateConversion::DecimalDegreesToPoint(coordinates, spatialRef);
}

EsriRuntimeQt::Point MapView::decimalDegreesToPoint(double lat, double lon){
    QString coord = QString::number(lat,'f',9) + ", " + QString::number(lon,'f',9);
    return decimalDegreesToPoint(coord);
}

QString MapView::pointToDecimalDegrees(EsriRuntimeQt::Point p){
    return EsriRuntimeQt::CoordinateConversion::PointToDecimalDegrees(p, 8);
}

bool MapView::rotateVehicleGraphic(Vehicle22& vehicle, int angle){
    vehicle.setAngle(angle);
    grLayer->updateGraphic(vehicle.getGraphicID(), vehicle.getGraphic());
    return true;
}
    
void MapView::onMousePress(QMouseEvent &event){
    EsriRuntimeQt::Point point = m_map->toMapPoint(event.pos().x(), event.pos().y());
    spatialRef = m_map->spatialReference();
    if(event.button() == Qt::LeftButton){
        qDebug() << "x: " << event.x() << " y: " << event.y();
        //EsriRuntimeQt::Point point = m_map->toMapPoint(event.x(), event.y());
        QList<double> latLon = coordinateStringToDoubles(EsriRuntimeQt::CoordinateConversion::PointToDecimalDegrees(
                                      EsriRuntimeQt::Point(point.x(), point.y(),spatialRef), 9));
        emit coordDesignated(latLon.at(0), latLon.at(1));
    }
}

QList<double> MapView::coordinateStringToDoubles(QString coordinates){
    QList<double> latLon;
    //Break into lat and lon
    QStringList list = coordinates.split(" ");

    //Negative lat
    if(list.at(0).contains("S")){
        latLon.append(-list.at(0).left(list.at(0).indexOf("S")).toDouble());
    }
    else{
        latLon.append(list.at(0).left(list.at(0).indexOf("N")).toDouble());
    }

    //Negative lon
    if(list.at(1).contains("W")){
        //latLon.append(-list.at(1).left(list.at(1).indexOf("W")).toDouble());
    }
    else{
       // latLon.append(list.at(1).left(list.at(1).indexOf("E")).toDouble());
    }
    return latLon;
}

void MapView::uavLayerOn(bool isOn) {
    uavLayer->setVisible(isOn);
}

void MapView::ugvLayerOn(bool isOn) {
    ugvLayer->setVisible(isOn);
}

void MapView::satelliteLayerOn(bool isOn) {
    satelliteLayer->setVisible(isOn);
    imageryLayer->setVisible(isOn);
}

void MapView::waypointLayerOn(bool isOn) {
    waypointLayer->setVisible(isOn);
}

void MapView::opspaceLayerOn(bool isOn) {
    opspaceLayer->setVisible(isOn);
}

void MapView::targetLayerOn(bool isOn) {
    targetLayer->setVisible(isOn);
}
