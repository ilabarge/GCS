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
    void telemetry(int);

public slots:
    void send_telemetry();
private:
    QGridLayout* mainLayout;
    QLineEdit* telemetryInput;
    QPushButton *Telemetry;

};

#endif // TELEMETRYGUI_H
