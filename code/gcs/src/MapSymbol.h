#ifndef MAPSYMBOL_H
#define MAPSYMBOL_H

#include <QColor>
#include <QObject>

#include <Graphic.h>
#include <PictureMarkerSymbol.h>
#include <Point.h>
#include <SimpleMarkerSymbol.h>

class MapSymbol
{

public:
    MapSymbol();
    MapSymbol(EsriRuntimeQt::Point, EsriRuntimeQt::PictureMarkerSymbol);
    ~MapSymbol();

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
    int setGraphic(const QString url, const int width, const int height);

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
    int setGraphic(const QString url, double lat, double lon, int width, int height);

    int setGraphic( const QColor& color, const EsriRuntimeQt::SimpleMarkerSymbolStyle shape, double lat, double lon, int size);
    bool setPoint(EsriRuntimeQt::Point point);
    bool setAngle(double angle);
    bool setGraphicID(int id);
    void setColor(QColor color);

    EsriRuntimeQt::Graphic getGraphic();
    EsriRuntimeQt::Point getPoint();
    EsriRuntimeQt::PictureMarkerSymbol getPMS();
    int getGraphicID();
    QColor getColor();

protected:
    QColor color;
    EsriRuntimeQt::Graphic graphic;
    EsriRuntimeQt::Point curr_Point;
    EsriRuntimeQt::PictureMarkerSymbol pmSymbol;
    EsriRuntimeQt::SimpleMarkerSymbol smSymbol;
    int graphicID; //ID for graphics layer
    bool pmExists;
    bool smExists;

//signals:
//    void GCSRemoveGraphic(int graphicID);
//    void GCSUpdateGraphic(int gID, EsriRuntimeQt::Graphic g);
};

#endif // MAPSYMBOL_H
