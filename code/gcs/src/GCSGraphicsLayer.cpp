#include "GCSGraphicsLayer.h"

#include <QDebug>

GCSGraphicsLayer::GCSGraphicsLayer()
{
    EsriRuntimeQt::SpatialReference spatialReference = this->spatialReference();
    // add simple line symbol
    EsriRuntimeQt::Point point10(600000,  -2000000, spatialReference);
    EsriRuntimeQt::Point point11(2000000, -3000000, spatialReference);
    EsriRuntimeQt::Point point12(3400000, -2000000, spatialReference);
    QList<EsriRuntimeQt::Point> pointList;
    pointList.append(point10);
    pointList.append(point11);
    pointList.append(point12);
    QList<QList<EsriRuntimeQt::Point> > tmpList;
    tmpList.append(pointList);

    EsriRuntimeQt::Polyline line1(tmpList);
    QColor qcRed;
    qcRed.setRgb(255,0,0);
    EsriRuntimeQt::SimpleLineSymbol simpleLineSym;
    simpleLineSym.setColor(qcRed);
    simpleLineSym.setWidth(3);
    simpleLineSym.setStyle(EsriRuntimeQt::SimpleLineSymbolStyle::DashDot);
    EsriRuntimeQt::Graphic* graphic10 = new EsriRuntimeQt::Graphic(line1, simpleLineSym);
    this->addGraphic(graphic10);
}

void GCSGraphicsLayer::removeLayerGraphic(int gID){
    removeGraphic(gID);
    qDebug() << "Remove " << gID;
}

void GCSGraphicsLayer::removeWaypointGraphic(int waypointID, int lineID){
    removeGraphic(lineID);
    removeGraphic(waypointID);
    qDebug() << "Remove Waypoint" << waypointID;
}

void GCSGraphicsLayer::updateLayerGraphic(int gID, EsriRuntimeQt::Graphic *graphic){
    updateGraphic(gID, graphic);
    qDebug() << "Update " << gID;
}

void GCSGraphicsLayer::addWaypointToGCS( Waypoint22* wp, QColor color){
    wp->setLinePoints(decimalDegreesToPoint(wp->getLatitude(), wp->getLongitude()),
                      decimalDegreesToPoint(wp->getNextLatitude(), wp->getNextLongitude()));

    wp->setGraphic(color, EsriRuntimeQt::SimpleMarkerSymbolStyle::Square, decimalDegreesToPoint(wp->getLatitude(), wp->getLongitude()), 20);

    addGraphic(wp->getLineGraphic());
    addGraphic(wp->getGraphic());
    qDebug() << "Waypoint added";
}

void GCSGraphicsLayer::addGraphicToGCS(EsriRuntimeQt::Graphic *graphic){
    addGraphic(graphic);
    qDebug() << "Adding";
}

void GCSGraphicsLayer::updateWaypointGraphics(Waypoint22 *wp){

    wp->setLinePoints(decimalDegreesToPoint(wp->getLatitude(), wp->getLongitude()),
                      decimalDegreesToPoint(wp->getNextLatitude(), wp->getNextLongitude()));

    updateGraphic(wp->getLineGraphicID(), wp->getLineGraphic());
    updateGraphic(wp->getGraphicID(), wp->getGraphic());

    qDebug() << "Updated waypoint";
}

EsriRuntimeQt::Point GCSGraphicsLayer::decimalDegreesToPoint(QString coordinates){
    return EsriRuntimeQt::CoordinateConversion::DecimalDegreesToPoint(coordinates, this->spatialReference());
}

EsriRuntimeQt::Point GCSGraphicsLayer::decimalDegreesToPoint(double lat, double lon){
    QString coord = QString::number(lat,'f',9) + ", " + QString::number(lon,'f',9);
    return decimalDegreesToPoint(coord);
}

QString GCSGraphicsLayer::pointToDecimalDegrees(EsriRuntimeQt::Point p){
    return EsriRuntimeQt::CoordinateConversion::PointToDecimalDegrees(p, 8);
}
