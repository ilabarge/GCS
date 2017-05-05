#ifndef TARGETINFO_H
#define TARGETINFO_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include "targetlist.h"
#include "target.h"
#include <QMutex>
#include <ctime>
#include <cmath>

class TargetInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit TargetInfo(QWidget *parent = 0);
    void getList(TargetList *);
    ~TargetInfo();
    TargetList *tl;
    int currentTarget;

signals:

public slots:
    void tStatus(int);
    void displayTargetInfo(int tID);

private:
    QGridLayout *info;
    QLabel *vehicleID;
    QLabel *payloadID;
    QLabel *targetID;
    QLabel *targetType;
    QLabel *latitude;
    QLabel *longitude;

    QLabel *vechUp;
    QLabel *payUp;
    QLabel *targUp;
    QLabel *typeUp;
    QLabel *latUp;
    QLabel *lonUp;
};

#endif // TARGETINFO_H
