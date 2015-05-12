#include "MapSymbol22.h"

MapSymbol22::MapSymbol22(QObject *parent) :
    QObject(parent)
{}

MapSymbol22::MapSymbol22(EsriRuntimeQt::Point point, EsriRuntimeQt::PictureMarkerSymbol symbol){
    graphic = EsriRuntimeQt::Graphic(point, symbol);
    color = Qt::black;
    pmExists = false;
    smExists = false;
}

int MapSymbol22::setGraphic( const QColor& color, const EsriRuntimeQt::SimpleMarkerSymbolStyle shape, double x, double y, int size){
    this->color = color;
    smSymbol = EsriRuntimeQt::SimpleMarkerSymbol(this->color, size, shape);
    curr_Point = EsriRuntimeQt::Point(x, y);
    graphic = EsriRuntimeQt::Graphic(curr_Point, smSymbol);
    smExists = true;
    return 0;
}

int MapSymbol22::setGraphic( const QColor& color, const EsriRuntimeQt::SimpleMarkerSymbolStyle shape, EsriRuntimeQt::Point p, int size){
    this->color = color;
    smSymbol = EsriRuntimeQt::SimpleMarkerSymbol(this->color, size, shape);
    curr_Point = p;
    graphic = EsriRuntimeQt::Graphic(curr_Point, smSymbol);
    smExists = true;
    return 0;
}

int MapSymbol22::setGraphic(const QString url, const int width, const int height){
    return setGraphic(url, 0, 0, width, height);
}

int MapSymbol22::setGraphic(const QString url, double x, double y, const int width, const int height){
    QImage img;
    if(!img.load(url)){
        return -1;
    }
    pmSymbol = EsriRuntimeQt::PictureMarkerSymbol(img, width, height);
    curr_Point = EsriRuntimeQt::Point(x, y);
    graphic = EsriRuntimeQt::Graphic(curr_Point, pmSymbol);
    pmExists = true;
    return 0;
}

bool MapSymbol22::setPoint(const EsriRuntimeQt::Point point) {
    curr_Point = point;
    return true;
}

bool MapSymbol22::setAngle(double angle){
    if(pmExists){
        pmSymbol.setAngle((int)(angle) % 360);
    }
    else if(smExists){
        smSymbol.setAngle((int)(angle) % 360);
    }
    else{
        return false;
    }
    return true;
}

void MapSymbol22::setColor(QColor color){
    this->color = color;
}

void MapSymbol22::updateGraphic(){
    if(smExists){
        graphic = EsriRuntimeQt::Graphic(curr_Point, smSymbol);
    }
    else if(pmExists){
        graphic = EsriRuntimeQt::Graphic(curr_Point, pmSymbol);
    }
}

