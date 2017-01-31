#ifndef MAPSYMBOL22_H
#define MAPSYMBOL22_H

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

#include <QObject>
#include <QColor>
#include <QString>

#include <Point.h>
#include <PictureMarkerSymbol.h>
#include <SimpleMarkerSymbol.h>
#include <Graphic.h>
#include <CoordinateConversion.h>

class MapSymbol22 : public QObject
{
    Q_OBJECT
public:
    explicit MapSymbol22(QObject *parent = 0);
    MapSymbol22(EsriRuntimeQt::Point, EsriRuntimeQt::PictureMarkerSymbol);

    /**
     * @brief MapSymbol::setGraphic
     * Set the graphic of this vehicle.
     *
     * @param url  The url of the image to use.
     * @param size Size of the image.
     * @return
     * -1: Bad image URL
     *  0: Success
     */
    int setGraphic(const QString url, const int width, const int height, EsriRuntimeQt::SpatialReference spatialReference);

    /**
     * @brief MapSymbol::setGraphic
     * Set the graphic of this vehicle.
     *
     * @param url  The url of the image to use.
     * @param lat  The latitude of the vehicle.
     * @param lon  The longitude of the vehicle.
     * @param size Size of the image.
     * @return
     * -1: Bad image URL
     *  0: Success
     */
    int setGraphic(const QString url, double lat, double lon, int width, int height, EsriRuntimeQt::SpatialReference spatialReference);

    int setGraphic( const QColor& color, const EsriRuntimeQt::SimpleMarkerSymbolStyle shape, double x, double y, int size, EsriRuntimeQt::SpatialReference spatialReference);
    int setGraphic( const QColor& color, const EsriRuntimeQt::SimpleMarkerSymbolStyle shape, EsriRuntimeQt::Point p, int size);
    bool setPoint(EsriRuntimeQt::Point point);
    bool setAngle(double angle);
    void setColor(QColor color);

    EsriRuntimeQt::Graphic* getGraphic(){ return graphic; }
    EsriRuntimeQt::Point getPoint(){ return curr_Point; }
    EsriRuntimeQt::PictureMarkerSymbol getPMS(){ return pmSymbol; }
    EsriRuntimeQt::PictureMarkerSymbol getSMS(){ return smSymbol; }
    //ESRI 10.2.5 update change from uid to uniqueID
    int getGraphicID(){ return graphic->uniqueId(); }
    QColor getColor(){ return color; }

    EsriRuntimeQt::Point decimalDegreesToPoint(double lat, double lon);

    void updateGraphic();

protected:
    QColor color;
    EsriRuntimeQt::Graphic *graphic;
    EsriRuntimeQt::Point curr_Point;
    EsriRuntimeQt::PictureMarkerSymbol pmSymbol;
    EsriRuntimeQt::SimpleMarkerSymbol smSymbol;
    int graphicID; //ID for graphics layer
    bool smExists;
    bool pmExists;

signals:
    void GCSRemoveGraphic(int graphicID);
    void GCSUpdateGraphic(int gID, EsriRuntimeQt::Graphic *graphic);

public slots:

};

#endif // MAPSYMBOL22_H
