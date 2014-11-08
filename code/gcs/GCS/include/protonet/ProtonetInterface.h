#ifndef PROTONETINTERFACE_H
#define PROTONETINTERFACE_H
#include <QObject>
#include "protonet.h"

class ProtonetInterface : public QObject
{
    Q_OBJECT
public:
    ProtonetInterface();
    ~ProtonetInterface();
private:
protonet::node* interfaceNode;


public slots:

void startNode(uint8_t id);
void stopNode();

void addSerialDatalink(int8_t* linkID /*out*/, uint32_t baudRate,char* devicePath);
void addUDPDatalink(int8_t* linkID/*out*/, uint16_t port,char* addr);

void establishSerialEndpoint(int8_t linkID, uint8_t nodeID);
void establishUDPEndpoint(int8_t linkID, uint8_t nodeID, uint16_t port,char* addr);

void removeSerialDatalink(int8_t linkID);
void removeUDPDatalink(int8_t linkID);

void sendPing(int8_t dest_id);

signals:
void nodeStarted(uint8_t nodeID);
};



#endif // PROTONETINTERFACE_H
