/********************************************************************************
** Form generated from reading UI file 'WidgetSix.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSIX_H
#define UI_WIDGETSIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "WidgetADI.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetSix
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    WidgetADI *widgetADI;

    void setupUi(QWidget *WidgetSix)
    {
        if (WidgetSix->objectName().isEmpty())
            WidgetSix->setObjectName(QStringLiteral("WidgetSix"));
        WidgetSix->resize(400, 300);
        gridLayout_2 = new QGridLayout(WidgetSix);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widgetADI = new WidgetADI(WidgetSix);
        widgetADI->setObjectName(QStringLiteral("widgetADI"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetADI->sizePolicy().hasHeightForWidth());
        widgetADI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetADI, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(WidgetSix);

        QMetaObject::connectSlotsByName(WidgetSix);
    } // setupUi

    void retranslateUi(QWidget *WidgetSix)
    {
        WidgetSix->setWindowTitle(QApplication::translate("WidgetSix", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class WidgetSix: public Ui_WidgetSix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSIX_H
