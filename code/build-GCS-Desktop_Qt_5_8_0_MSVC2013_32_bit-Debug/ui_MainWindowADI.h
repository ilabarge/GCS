/********************************************************************************
** Form generated from reading UI file 'MainWindowADI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWADI_H
#define UI_MAINWINDOWADI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "WidgetSix.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowADI
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    WidgetSix *widgetSix;

    void setupUi(QMainWindow *MainWindowADI)
    {
        if (MainWindowADI->objectName().isEmpty())
            MainWindowADI->setObjectName(QStringLiteral("MainWindowADI"));
        MainWindowADI->resize(734, 492);
        centralWidget = new QWidget(MainWindowADI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widgetSix = new WidgetSix(frame_2);
        widgetSix->setObjectName(QStringLiteral("widgetSix"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetSix->sizePolicy().hasHeightForWidth());
        widgetSix->setSizePolicy(sizePolicy);
        widgetSix->setMaximumSize(QSize(678, 16777215));

        gridLayout_2->addWidget(widgetSix, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        splitter->addWidget(frame_2);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        MainWindowADI->setCentralWidget(centralWidget);

        retranslateUi(MainWindowADI);

        QMetaObject::connectSlotsByName(MainWindowADI);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowADI)
    {
        MainWindowADI->setWindowTitle(QApplication::translate("MainWindowADI", "QFlightInstruments Example", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowADI: public Ui_MainWindowADI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWADI_H
