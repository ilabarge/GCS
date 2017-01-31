/*
GCS Toolbar Widget
*/

/********************************************************************************
** Form generated from reading UI file 'gcs_toolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GCS_TOOLBAR_H
#define UI_GCS_TOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GcsToolbar
{
public:
    QAction *actionMap_View;
    QAction *actionPayload;
    QAction *actionZoning;
    QAction *actionWaypoints;
    QAction *actionSettings;
    QAction *actionCPP_UAV;
    QAction *actionSLO_UAV;
    QAction *actionCPP_UGV;
    QAction *actionSLO_UGV;
    QAction *actionCPP_UAV2;
    QMenuBar *menuBar;
    QMenu *menuViews;
    QMenu *menuUAV_View;
    QMenu *menuUGV_View;
    QMenu *menuActions;
    QMenu *menuSettings;
    QMenu *menu_File;

    void setupUi(QWidget *GcsToolbar)
    {
        if (GcsToolbar->objectName().isEmpty())
            GcsToolbar->setObjectName(QStringLiteral("GcsToolbar"));
        GcsToolbar->resize(680, 145);
        actionMap_View = new QAction(GcsToolbar);
        actionMap_View->setObjectName(QStringLiteral("actionMap_View"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("default");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/gcs_tb/icons/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionMap_View->setIcon(icon);
        actionMap_View->setIconVisibleInMenu(false);
        actionPayload = new QAction(GcsToolbar);
        actionPayload->setObjectName(QStringLiteral("actionPayload"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/gcs_tb/icons/payload.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPayload->setIcon(icon1);
        actionZoning = new QAction(GcsToolbar);
        actionZoning->setObjectName(QStringLiteral("actionZoning"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/gcs_tb/icons/zone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoning->setIcon(icon2);
        actionWaypoints = new QAction(GcsToolbar);
        actionWaypoints->setObjectName(QStringLiteral("actionWaypoints"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/gcs_tb/icons/waypoint.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWaypoints->setIcon(icon3);
        actionSettings = new QAction(GcsToolbar);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/gcs_tb/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon4);
        actionCPP_UAV = new QAction(GcsToolbar);
        actionCPP_UAV->setObjectName(QStringLiteral("actionCPP_UAV"));
        actionSLO_UAV = new QAction(GcsToolbar);
        actionSLO_UAV->setObjectName(QStringLiteral("actionSLO_UAV"));
        actionCPP_UGV = new QAction(GcsToolbar);
        actionCPP_UGV->setObjectName(QStringLiteral("actionCPP_UGV"));
        actionSLO_UGV = new QAction(GcsToolbar);
        actionSLO_UGV->setObjectName(QStringLiteral("actionSLO_UGV"));
        actionCPP_UAV2 = new QAction(GcsToolbar);
        actionCPP_UAV2->setObjectName(QStringLiteral("actionCPP_UAV2"));
        menuBar = new QMenuBar(GcsToolbar);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 22));
        menuViews = new QMenu(menuBar);
        menuViews->setObjectName(QStringLiteral("menuViews"));
        menuUAV_View = new QMenu(menuViews);
        menuUAV_View->setObjectName(QStringLiteral("menuUAV_View"));
        menuUGV_View = new QMenu(menuViews);
        menuUGV_View->setObjectName(QStringLiteral("menuUGV_View"));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QStringLiteral("menuActions"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuViews->menuAction());
        menuBar->addAction(menuActions->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuViews->addAction(actionMap_View);
        menuViews->addAction(menuUAV_View->menuAction());
        menuViews->addAction(menuUGV_View->menuAction());
        menuViews->addSeparator();
        menuUAV_View->addAction(actionCPP_UAV);
        menuUAV_View->addAction(actionCPP_UAV2);
        menuUAV_View->addAction(actionSLO_UAV);
        menuUGV_View->addAction(actionCPP_UGV);
        menuUGV_View->addAction(actionSLO_UGV);
        menuActions->addAction(actionZoning);
        menuActions->addAction(actionWaypoints);
        menuActions->addSeparator();
        menuActions->addAction(actionPayload);
        menu_File->addAction(actionSettings);

        retranslateUi(GcsToolbar);

        QMetaObject::connectSlotsByName(GcsToolbar);
    } // setupUi

    void retranslateUi(QWidget *GcsToolbar)
    {
        actionMap_View->setText(QApplication::translate("GcsToolbar", "Map View", 0));
        actionPayload->setText(QApplication::translate("GcsToolbar", "Deploy Payload", 0));
        actionZoning->setText(QApplication::translate("GcsToolbar", "Edit Zones", 0));
        actionWaypoints->setText(QApplication::translate("GcsToolbar", "Edit Waypoints", 0));
        actionSettings->setText(QApplication::translate("GcsToolbar", "Settings", 0));
        actionCPP_UAV->setText(QApplication::translate("GcsToolbar", "CPP UAV", 0));
        actionSLO_UAV->setText(QApplication::translate("GcsToolbar", "SLO UAV", 0));
        actionCPP_UGV->setText(QApplication::translate("GcsToolbar", "CPP UGV", 0));
        actionSLO_UGV->setText(QApplication::translate("GcsToolbar", "SLO UGV", 0));
        actionCPP_UAV2->setText(QApplication::translate("GcsToolbar", "CPP UAV2", 0));
        menuViews->setTitle(QApplication::translate("GcsToolbar", "Views", 0));
        menuUAV_View->setTitle(QApplication::translate("GcsToolbar", "UAV View", 0));
        menuUGV_View->setTitle(QApplication::translate("GcsToolbar", "UGV View", 0));
        menuActions->setTitle(QApplication::translate("GcsToolbar", "Actions", 0));
        menuSettings->setTitle(QApplication::translate("GcsToolbar", "Settings", 0));
        menu_File->setTitle(QApplication::translate("GcsToolbar", "&File", 0));
        Q_UNUSED(GcsToolbar);
    } // retranslateUi

};

namespace Ui {
    class GcsToolbar: public Ui_GcsToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GCS_TOOLBAR_H
