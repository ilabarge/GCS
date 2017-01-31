#ifndef TELEMETRYGUI_H
#define TELEMETRYGUI_H
//Qt headers
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class TelemetryGUI : public QWidget
{
    Q_OBJECT
public:
    explicit TelemetryGUI(QWidget *parent = 0);

signals:
    //Holds the vehicle ID whose telemetry we want to access
    void telemetry(int);

public slots:
    //Takes the QPushbutton as a signal to start
    void send_telemetry();

private:
    //Layout for the wiedget
    QGridLayout* mainLayout;
    //Input for vehicle ID
    QLineEdit* telemetryInput;
    //Button to send the ID as a signal
    QPushButton *Telemetry;

};

#endif // TELEMETRYGUI_H
