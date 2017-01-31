#ifndef VEHICLEAUTHORIZATIONGUI_H
#define VEHICLEAUTHORIZATIONGUI_H
//Qt headers
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class VehicleAuthorizationGUI : public QWidget
{
    Q_OBJECT
public:
    explicit VehicleAuthorizationGUI(QWidget *parent = 0);

signals:
    void authorize(int);
public slots:
    void send_authorization();

private:
    QGridLayout* mainLayout;
    QLineEdit* vehicle;
    QPushButton *Authorization;
};

#endif // VEHICLEAUTHORIZATIONGUI_H
