#include <QCoreApplication>
#include <QThread>
#include "protoface.h"
#include "rx_thread.h"
#include "testing.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Testing *b = new Testing();
    return a.exec();
}
