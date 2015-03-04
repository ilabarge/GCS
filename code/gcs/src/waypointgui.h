#ifndef WAYPOINTGUI_H
#define WAYPOINTGUI_H

//Qt Includes
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMutex>
#include <QLabel>
#include <QString>

//Vehicle Includes
#include "Vehicle22.h"
#include "Waypoint22.h"

class WaypointGUI : public QWidget
{
    Q_OBJECT
public:
    explicit WaypointGUI(QWidget *parent = 0);

signals:
    void waypoint(Waypoint22*,int);
    void addWaypoint(int,Waypoint22*);

public slots:
    void send_waypoint();
    void coordDesignated(double lat, double lon);

private:
    void initGUIElements();
    void setGUIElementText();
    void addGUIElementToLayout();
    QGridLayout* mainLayout;
    QLineEdit* vehicle;
    QLineEdit* latitude;
    QLineEdit* longitude;
    QLineEdit* altitude;
    QLineEdit* heading;
    QLineEdit* id;
    QLineEdit* type;
    Vehicle22* v;

    QLabel *vIDLabel, *wIDLabel, *typeLabel, *latLabel, *lonLabel, *altLabel, *headingLabel;

    QPushButton *WaypointB;
    QMutex mutex;

};

#endif // WAYPOINTGUI_H
