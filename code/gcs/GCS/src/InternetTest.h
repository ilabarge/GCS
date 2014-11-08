#ifndef INTERNETTEST_H
#define INTERNETTEST_H

#include <QObject>
#include <QTcpSocket>

class InternetTest : public QObject
{
    Q_OBJECT
public:
    explicit InternetTest(QObject *parent = 0);
    bool isConnected();

signals:

private:
    QTcpSocket *socket;

};

#endif // INTERNETTEST_H
