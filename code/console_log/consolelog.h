#ifndef CONSOLELOG_H
#define CONSOLELOG_H

#include <QTextEdit>
#include <QWidget>
#include <QGridLayout>
#include <QColor>
#include <QPalette>
class consolelog : public QWidget
{
    Q_OBJECT

public:
    consolelog(QWidget *parent = 0);
    ~consolelog();
    void displayMessage(QString);
    void displayMessageAlert(QString);
    void displayMessageConfirm(QString);

private:
     QTextEdit *log;
     void startOfMessage();
};

#endif // CONSOLELOG_H
