#ifndef NETWORKING_H
#define NETWORKING_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <iostream>
#include "rx_thread.h"
#include "ProtonetInterface.h"
#include "Vehicle.h"
#include "serialscanner.h"

class networking : public QObject
{
    Q_OBJECT
public:
    networking(QVector<Vehicle*>* v);
    ~networking();
    void invokeThread(QVector<Vehicle*>* v, uint8_t node_id, uint16_t self_port, uint16_t dest_port, std::string serial_port);
    QString serialSelection();
private:
    rx_thread* rx;
    QThread* network_thread;
};

#endif // NETWORKING_H
