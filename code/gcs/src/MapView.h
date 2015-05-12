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

#ifndef MAP_VIEW_H
#define MAP_VIEW_H

namespace EsriRuntimeQt
{
class MapGraphicsView;
}

//ArcGIS headers
#include "Map.h"
//Uncommented layer(s) needed
#include "ArcGISLocalTiledLayer.h"
#include "ArcGISTiledMapServiceLayer.h"
//#include "LocalMapService.h"
//#include "ArcGISDynamicMapServiceLayer.h"
//#include "LocalFeatureService.h"
//#include "ArcGISFeatureLayer.h"

//#include "GraphicsLayer.h"
#include "SimpleMarkerSymbol.h"
#include "Point.h"
#include "PictureMarkerSymbol.h"
#include "CoordinateConversion.h"

//Qt headers
#include <QMainWindow>
#include <QLinkedList>
#include <QDebug>
#include <QList>

//Our headers
#include "GCSGraphicsLayer.h"
#include "Vehicle22.h"
#include "InternetTest.h"

class MapView : public QWidget
{
    Q_OBJECT
public:
    MapView (QWidget *parent = 0);
    ~MapView ();

    EsriRuntimeQt::MapGraphicsView* m_mapGraphicsView;

    enum Layers{
        UGV,
        UAV,
        TARGET,
        SATELLITE,
        WAYPOINT,
        ZONE
    };

    //Layer Access Methods
    void UAVLayerVisible(bool);
    void UGVLayerVisible(bool);
    void waypointLayerVisible(bool);
    void zoneLayerVisible(bool);
    void targetLayerVisible(bool);
    void satelliteLayerVisible(bool);

    /**
     * @brief MapView::moveGraphic
     * Move the specified graphic to the desired point.
     *
     * @param vehicle   The vehicle to get the graphic from.
     * @param p         The point to move to.
     * @return          true on success, false on fail.
     */
    bool moveVehicleGraphic(Vehicle22& vehicle, const EsriRuntimeQt::Point p);

    /**
     * @brief MapView::moveGraphic
     * Move the specified graphic to the desired point.
     *
     * @param vehicle   The vehicle to get the graphic from.
     * @param lat       The latitude.
     * @param lon       The longitude.
     * @return          true on success, false on fail.
     */
    bool moveVehicleGraphic(Vehicle22& vehicle, double lat, double lon);

    bool moveLayerGraphic(Layers layer, EsriRuntimeQt::Graphic& graphic, const EsriRuntimeQt::Point p);
    bool moveLayerGraphic(Layers layer, EsriRuntimeQt::Graphic& graphic, double lat, double lon);

    /**
     * @brief rotateVehicleGraphic
     * Rotate the specified vehicle's graphic by the specified angle. The
     * rotation is counter-clockwise.
     *
     * @param vehicle   The vehicle to rotate.
     * @param angle     Counter-clockwise angle to rotate.
     * @return          true on success, false on fail.
     */
    bool rotateVehicleGraphic(Vehicle22& vehicle, int angle);

    /**
     * @brief addGraphicToLayer
     * Add graphic to the map layer.
     *
     * @param v     The vehicle to add.
     * @return      true on success, false on fail.
     */
    bool addGraphicToLayer(EsriRuntimeQt::Graphic& graphic);

    //Conversion Methods
    /**
     * @brief decimalDegreesToPoint
     * Convert the string with decimal degree formatted coordinates to an Esri Runtime Point.
     *
     * @param coordinates   The string with the decimal degree coordinates.
     * @return              The converted point. NULL on failure to convert.
     */
    EsriRuntimeQt::Point decimalDegreesToPoint(QString coordinates);

    /**
     * @brief decimalDegreesToPoint
     * Convert the latitude and longitude to an Esri Runtime Point.
     *
     * @param lat   The latitude in decimal format.
     * @param lon   The longitude in decimal format.
     * @return      The converted point. NULL on failure to convert.
     */
    EsriRuntimeQt::Point decimalDegreesToPoint(double lat, double lon);

    QString MapView::pointToDecimalDegrees(EsriRuntimeQt::Point p);

    GCSGraphicsLayer* getVehicleLayer(){ return grLayer; }

    QList<double> coordinateStringToDoubles(QString coordinates);

    /** Returns the spatial reference of the map to be used to set points
     * @brief getSpatialRef
     * @return
     */
    EsriRuntimeQt::SpatialReference getSpatialRef() { return spatialRef; }

public slots:
    void onMapReady();
    //  void onLocalServiceCreationSuccess(const QString& url, const QString& name);
    //  void onLocalServiceCreationFailure(const QString& name);
    //  void onFeatureServiceCreationSuccess(const QString& url, const QString& name);
    //  void onFeatureServiceCreationFailure(const QString& name);
    void uavLayerOn(bool isOn);
    void ugvLayerOn(bool isOn);
    void waypointLayerOn(bool isOn);
    void satelliteLayerOn(bool isOn);
    void opspaceLayerOn(bool isOn);
    void targetLayerOn(bool isOn);

private slots:
    void onMousePress(QMouseEvent event);

signals:
    void MapReady();
    void coordDesignated(double, double);

private:
    EsriRuntimeQt::Map m_map;
    //Update 10.2.5
    /*changed layers to pointers as they are singletons
     meaning that we cannot copy the values of the map layer
     we must copy the address of the created object*/
    EsriRuntimeQt::ArcGISLocalTiledLayer *m_tiledLayer;
    EsriRuntimeQt::ArcGISTiledMapServiceLayer *m_tiledServiceLayer;
    EsriRuntimeQt::ArcGISTiledMapServiceLayer *imageryLayer;

    //  EsriRuntimeQt::ArcGISDynamicMapServiceLayer m_dynamicServiceLayer;
    //  EsriRuntimeQt::LocalMapService m_localMapService;
    //  EsriRuntimeQt::ArcGISDynamicMapServiceLayer m_dynamicLocalServiceLayer;
    //  EsriRuntimeQt::LocalFeatureService m_localFeatureService;
    //  EsriRuntimeQt::ArcGISFeatureLayer m_localFeatureLayer;
    //  EsriRuntimeQt::GraphicsLayer m_graphicsLayer;
    //  EsriRuntimeQt::ArcGISFeatureLayer m_featureLayer;

    GCSGraphicsLayer *uavLayer;
    GCSGraphicsLayer *ugvLayer;
    GCSGraphicsLayer *waypointLayer;
    GCSGraphicsLayer *opspaceLayer;
    GCSGraphicsLayer *targetLayer;
    GCSGraphicsLayer *satelliteLayer;

    GCSGraphicsLayer *grLayer;
    EsriRuntimeQt::SpatialReference spatialRef;
    InternetTest it;
};

#endif // MAP_VIEW_H

