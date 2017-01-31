#ifndef COMMSGUI_H
#define COMMSGUI_H
#include <Qt>
#include <QWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QFormLayout>
#include <QObject>

namespace Ui {
class CommsGUI;
}

class CommsGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CommsGUI(QWidget *parent = 0);
    ~CommsGUI();

private:
    QGroupBox *createCommsBoxGroup();
    QGroupBox *createToggleGroup();
    QLabel * alt;
    QLabel * spd;
    QLabel * altNum;
    QLabel * altNum2;
    QLabel * altNum3;
    QLabel * altNum4;
    QLabel * spdNum;
    QLabel * spdNum2;
    QLabel * spdNum3;
    QLabel * spdNum4;

};

#endif // COMMSGUI_H
