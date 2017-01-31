#ifndef UGV_STATE_H
#define UGV_STATE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class UGV_state : public QWidget
{
    Q_OBJECT
public:
    explicit UGV_state(QWidget *parent = 0);

signals:
    void ManualToAuto();
    void AutoToManual();
    void Reset();
    void DisableMotor();
    void EnableMotor();
    void ToggleMotor();

public slots:
    void r();        //reset
    void ATM();      //auto to manual
    void MTA();      //manual to auto
    void DisableM(); //disable motor
    void EnableM();  //enable motor
    void ToggleM();  //toggle motor

private:
    QGridLayout* mainLayout;
    QPushButton* manauto;
    QPushButton* automan;
    QPushButton* rst;
    QPushButton* DisableMot;
    QPushButton* EnableMot;
    QPushButton* ToggleMot;
};

#endif // UGV_STATE_H
