#ifndef RX_THREAD_H
#define RX_THREAD_H
#include <QObject>
#include <QStringList>
#include <string>
#include "protonet.h"
#include "Vehicle.h"
class rx_thread : public QObject
{
    Q_OBJECT
public:
    rx_thread(uint8_t, uint16_t, uint16_t, QVector<Vehicle*>*, std::string);
    rx_thread();
    void print_port();
    ~rx_thread();

private:
    uint8_t node_id;
    uint16_t self_port;
    uint16_t dest_port;
    char serial_port[25];
    protonet::node *node;

public slots:
    void process();
signals:
    void finished();
    void error(QString err);
};

#endif // RX_THREAD_H
