#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H
#include <QtWidgets>
#include <QMainWindow>

class toggleButton : public QWidget
{
    Q_OBJECT

public:
    explicit toggleButton(QWidget *parent = 0);
    void setIcon(QIcon);
    void setIconSize(QSize);
    bool checkVisibility();
     ~toggleButton();

signals:
    void toggled();

private slots:
    void check();

private:
    QPushButton *button;
    bool visibility;
};

#endif // TOGGLEBUTTON_H
