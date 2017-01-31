#include <QtWidgets>
#include <QMainWindow>
#include "../include/togglebutton.h"

toggleButton::toggleButton(QWidget *parent): QWidget(parent)
{
    visibility = true;
    button = new QPushButton();
    button ->setStyleSheet("QPushButton { border : 0px; border-radius: 0px;max-width: 80px; }");
    connect(button, SIGNAL(clicked()), this, SLOT(check()));
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout ->setContentsMargins(0,0,0,0);
        mainLayout ->setVerticalSpacing(0);
    mainLayout->addWidget(button);
    setLayout(mainLayout);
}

void toggleButton::setIcon(QIcon icon)
{
    button -> setIcon(icon);
}

void toggleButton::setIconSize(QSize size)
{
    button -> setIconSize(size);
}

void toggleButton::check()
{
    if(visibility)
    {
        visibility = false;
        emit toggled();
    }
    else
    {
        visibility = true;
        emit toggled();
    }
}

bool toggleButton::checkVisibility()
{
    return visibility;
}

toggleButton::~toggleButton()
{
       delete button;
}
