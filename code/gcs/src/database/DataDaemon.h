#ifndef DATADAEMON_H
#define DATADAEMON_H

#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QFileInfo>
#include <QDebug>
#include <QVector>
#include <QDir>

#include "Vehicle22.h"

class DataDaemon : public QObject
{
    Q_OBJECT
public:
    explicit DataDaemon(QObject *parent = 0);
    void log(QVector<Vehicle22*> &);

signals:

public slots:

private:
    QSqlDatabase db;                                // Main Database Variable
};

#endif // DATADAEMON_H
