#ifndef DATADAEMON_H
#define DATADAEMON_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QDebug>
#include <QVector>
#include <QDir>

#include "Vehicle.h"

class DataDaemon : public QObject
{
    Q_OBJECT
public:
    explicit DataDaemon(QObject *parent = 0);
    void log(QVector<Vehicle> &);

signals:

public slots:

private:
    QSqlDatabase db;                                // Main Database Variable
};

#endif // DATADAEMON_H
