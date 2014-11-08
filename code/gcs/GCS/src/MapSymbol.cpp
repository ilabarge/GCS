#include "mapsymbol.h"

MapSymbol::MapSymbol(){}

MapSymbol::MapSymbol(EsriRuntimeQt::Point point, EsriRuntimeQt::PictureMarkerSymbol symbol)
{
    graphic = EsriRuntimeQt::Graphic(point, symbol);
    pmExists = false;
    smExists = false;
    color = Qt::black;
}

EsriRuntimeQt::Graphic MapSymbol::getGraphic(){
    return graphic;
}

EsriRuntimeQt::Point MapSymbol::getPoint(){
    return curr_Point;
}

EsriRuntimeQt::PictureMarkerSymbol MapSymbol::getPMS(){
    return pmSymbol;
}

int MapSymbol::getGraphicID(){
    return graphicID;
}

bool MapSymbol::setPoint(const EsriRuntimeQt::Point point) {
    curr_Point = point;
    return true;
}

int MapSymbol::setGraphic(const QString url, const int width, const int height){
    return setGraphic(url, 0, 0, width, height);
}

int MapSymbol::setGraphic( const QColor& color, const EsriRuntimeQt::SimpleMarkerSymbolStyle shape, double lat, double lon, int size){
    this->color = color;
    smSymbol = EsriRuntimeQt::SimpleMarkerSymbol(this->color, size, shape);
    curr_Point = EsriRuntimeQt::Point(lat, lon);
    graphic = EsriRuntimeQt::Graphic(curr_Point, smSymbol);
    smExists = true;
    return 0;
}

int MapSymbol::setGraphic(const QString url, double lat, double lon, const int width, const int height){
    QImage img;
    if(!img.load(url)){
        return -1;
    }
    pmSymbol = EsriRuntimeQt::PictureMarkerSymbol(img, width, height);
    curr_Point = EsriRuntimeQt::Point(lat, lon);
    graphic = EsriRuntimeQt::Graphic(curr_Point, pmSymbol);
    pmExists = true;
    return 0;
}

bool MapSymbol::setAngle(double angle){
    if(pmExists){
        pmSymbol.setAngle((int)(angle) % 360);
    }
    if(smExists){
        smSymbol.setAngle((int)(angle) % 360);
    }
    else{
        return false;
    }
    graphic = EsriRuntimeQt::Graphic(curr_Point, pmSymbol);
    return true;
}

bool MapSymbol::setGraphicID(int id){
    //Could check for negatives?
    graphicID = id;
    return true;
}

void MapSymbol::setColor(QColor color){
    this->color = color;
}

QColor MapSymbol::getColor(){
    return color;
}

MapSymbol::~MapSymbol(){}
