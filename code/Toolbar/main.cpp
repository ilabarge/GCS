#include "gcs_toolbar.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMenuBar>
#include <QDebug>
#include <QAction>
#include <QIcon>
#include <QLabel>
#include <QScreen>
#include <QToolBar>
#include <QVBoxLayout>
#include <QToolButton>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QWidget *centralWidget = new QWidget;
    GcsToolbar *tb = new GcsToolbar();

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->setAlignment(Qt::AlignHCenter);
    vlayout->addWidget(tb);
    centralWidget->setLayout(vlayout);
    w.setCentralWidget(centralWidget);
    w.show();

    return a.exec();
}
