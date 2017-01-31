#ifndef SERIALSCANNER_H
#define SERIALSCANNER_H
#include <QString>
#include <QtSerialPort>
#include <QStringList>

class serialScanner : public QObject
{
    Q_OBJECT
public:
    serialScanner();
    QStringList ports();

private:
    QStringList portNames;
    int nPorts;

public slots:
    //void process();
signals:
    void finished();
    void error(QString err);
};

#endif // SERIALSCANNER_H
