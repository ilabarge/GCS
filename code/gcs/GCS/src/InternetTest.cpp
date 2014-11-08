#include "InternetTest.h"

InternetTest::InternetTest(QObject *parent) :
    QObject(parent)
{
}

bool InternetTest::isConnected()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("services.arcgisonline.com", 80);

    if(!socket->waitForConnected(1000))
    {
        return false;
    }
    return true;
}
