#include "consolelog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    consolelog w;
    w.show();
    w.displayMessage("Hello");
    w.displayMessageAlert("Collion avoid");
    w.displayMessageConfirm("Sent message");
    return a.exec();
}
