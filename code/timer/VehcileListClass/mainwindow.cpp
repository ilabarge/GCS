#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(5);

        treeWidgetItem("vechicle type","current speed","current altitude","connection g/r", "uptime");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void VehicleWindow::treeWidgetItem(QString name, QString velo, QString alt, QString comms, QString uptime)
{
    QTreeWidgetItem * tr = new QTreeWidgetItem(ui->treeWidget);
    tr->setText(0,name);
    tr->setText(1,velo);
    tr->setText(2,alt);
    tr->setText(3,comms);
    tr->setText(4,uptime);
}
