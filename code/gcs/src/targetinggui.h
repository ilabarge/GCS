#ifndef TARGETINGGUI_H
#define TARGETINGGUI_H

//Qt includes
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class targetingGUI : public QWidget
{
    Q_OBJECT
public:
    explicit targetingGUI(QWidget *parent = 0);

signals:
    void target(float,float,float);

public slots:
    void targetsend();

private:
   QGridLayout* mainLayout;
   QPushButton* targets;
   QLineEdit* latitude;
   QLineEdit* longitude;
   QLineEdit* altitude;

};

#endif // TARGETINGGUI_H
