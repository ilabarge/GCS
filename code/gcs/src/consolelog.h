#ifndef CONSOLELOG_H
#define CONSOLELOG_H

#include <QTextEdit>
#include <QWidget>
#include <QGridLayout>
#include <QColor>
#include <QPalette>
#include <QScrollBar>

class ConsoleLog : public QWidget
{
    Q_OBJECT

public:
    explicit ConsoleLog(QWidget *parent = 0);
    ~ConsoleLog();

public slots:
    void displayMessage(QString);
    void displayMessageAlert(QString);
    void displayMessageConfirm(QString);

private:
     QTextEdit *log;
     void startOfMessage();
};

#endif // CONSOLELOG_H
