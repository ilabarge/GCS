#include "consolelog.h"

ConsoleLog::ConsoleLog(QWidget *parent)
    :QWidget(parent)
{
    log = new QTextEdit();
    log->setReadOnly(true);
    //Set background color of TextEdit
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::black);
    log->setPalette(*palette);
    log->setMaximumHeight(300);
    log->setMaximumWidth(300);
    QGridLayout *logLayout = new QGridLayout();
    logLayout->addWidget(log,0,0);
    setLayout(logLayout);
}

ConsoleLog::~ConsoleLog()
{
    delete log;
}

void ConsoleLog::displayMessage(QString message)
{
    startOfMessage();
    log->insertHtml("<font color=\"White\">&nbsp;&nbsp;" + message + "</font><br>");
    (log->verticalScrollBar())->setValue((log->verticalScrollBar())->maximum());
}

void ConsoleLog::displayMessageAlert(QString message)
{
    startOfMessage();
    log->insertHtml("<font color=\"Red\">&nbsp;&nbsp;" + message + "</font><br>");
    (log->verticalScrollBar())->setValue((log->verticalScrollBar())->maximum());

}

void ConsoleLog::displayMessageConfirm(QString message)
{
    startOfMessage();
    log->insertHtml("<font color=\"Green\">&nbsp;&nbsp;" + message + "</font><br>");
    (log->verticalScrollBar())->setValue((log->verticalScrollBar())->maximum());
}

void ConsoleLog::startOfMessage()
{
    log->insertHtml("<font color=\"White\">>>  </font>");
}
