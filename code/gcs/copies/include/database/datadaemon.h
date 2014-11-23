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
#include <QApplication>

#include "include/database/Vehicle.h"

class datadaemon : public QObject
{
    Q_OBJECT
public:
    explicit datadaemon(QObject *parent = 0);
    void log(QVector<Vehicle> &);

signals:

public slots:

private:
    QSqlDatabase db;                                // Main Database Variable
};

#endif // DATADAEMON_H
