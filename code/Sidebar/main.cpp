#include "include/sidebar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sideBar w;
    w.show();

    return a.exec();
}
