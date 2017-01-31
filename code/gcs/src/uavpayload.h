#ifndef UAVPAYLOAD_H
#define UAVPAYLOAD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
class UAVPayload : public QWidget
{
    Q_OBJECT
public:
    explicit UAVPayload(QWidget *parent = 0);

signals:
    void arm(int);
    void disarm(int);

public slots:
    void armvech();
    void disarmvech();

private:
    QPushButton* arming;
    QPushButton* disarming;
    QGridLayout* mainLayout;
};

#endif // UAVPAYLOAD_H
