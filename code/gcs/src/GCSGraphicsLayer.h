#ifndef GCSGRAPHICSLAYER_H
#define GCSGRAPHICSLAYER_H

//ArcGIS Headers
#include <GraphicsLayer.h>
#include <CoordinateConversion.h>

//Our Headers
#include "Waypoint22.h"

class GCSGraphicsLayer : public EsriRuntimeQt::GraphicsLayer
{
    Q_OBJECT
public:
    GCSGraphicsLayer();

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

    QString pointToDecimalDegrees(EsriRuntimeQt::Point p);

    void setSpatialReference(EsriRuntimeQt::SpatialReference ref);

public slots:
    void removeLayerGraphic( int gID );
    void updateLayerGraphic( int gID, EsriRuntimeQt::Graphic *graphic );
    void addGraphicToGCS(EsriRuntimeQt::Graphic * );

    void addWaypointToGCS( Waypoint22* wp, QColor color);
    void updateWaypointGraphics( Waypoint22* wp );
    void removeWaypointGraphic( int waypointID, int lineID);

private:
    EsriRuntimeQt::SpatialReference spatialRef;
};

#endif // GCSGRAPHICSLAYER_H
