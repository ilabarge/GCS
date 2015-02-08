#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "qtimer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void showTime();
    void handleButton();
    void stopButton();
    void reset();
private:
    Ui::MainWindow *ui;
    QTime time;
    QTimer timer;
};

#endif // MAINWINDOW_H
