#include <QtWidgets>
#include <QMainWindow>
#include "togglebutton.h"

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

/**
 * @brief toggleButton::setIcon Sets the icon of the buttion
 * @param icon A QIcon that the button will have as its icon
 */
void toggleButton::setIcon(QIcon icon)
{
    button -> setIcon(icon);
}

/**
 * @brief toggleButton::setIconSize Sets the size of the button
 * @param size A QSize that resizes the button
 */
void toggleButton::setIconSize(QSize size)
{
    button -> setIconSize(size);
}

/**
 * @brief toggleButton::check emits that the button has been pressed
 */
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

/**
 * @brief toggleButton::checkVisibility Returns whether the button has been toggled or not
 * @return The toggle value of the button
 */
bool toggleButton::checkVisibility()
{
    return visibility;
}

toggleButton::~toggleButton()
{
       delete button;
}
