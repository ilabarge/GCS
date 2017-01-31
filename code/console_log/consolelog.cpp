#include "consolelog.h"

consolelog::consolelog(QWidget *parent)
    :QWidget(parent)
{
    log = new QTextEdit();
    log->setReadOnly(true);
    //Set background color of TextEdit
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::black);
    log->setPalette(*palette);
    QGridLayout *logLayout = new QGridLayout();
    logLayout->addWidget(log,0,0);
    setLayout(logLayout);
}

consolelog::~consolelog()
{
    delete log;
}

void consolelog::displayMessage(QString message)
{
    startOfMessage();
    log->insertHtml("<font color=\"White\">&nbsp;&nbsp;" + message + "</font><br>");
}

void consolelog::displayMessageAlert(QString message)
{
    startOfMessage();
    log->insertHtml("<font color=\"Red\">&nbsp;&nbsp;" + message + "</font><br>");
}

void consolelog::displayMessageConfirm(QString message)
{
    startOfMessage();
    log->insertHtml("<font color=\"Green\">&nbsp;&nbsp;" + message + "</font><br>");
}

void consolelog::startOfMessage()
{
    log->insertHtml("<font color=\"White\">>>  </font>");
}
