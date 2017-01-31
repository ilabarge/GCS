#ifndef GPSGEN_H
#define GPSGEN_H

#include <QObject>
#include <cstdlib>
#include <QDebug>
#include <Windows.h>

class GPSGen : public QObject
{
    Q_OBJECT
public:
    explicit GPSGen(int,QObject *parent = 0);

signals:
    void gpsMSG(int,double,double,double,double,double,double,double);

public slots:
    void generateGPS();

private:
    int vechID;
};

#endif // GPSGEN_H
