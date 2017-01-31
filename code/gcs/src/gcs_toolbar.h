#ifndef GCS_TOOLBAR_H
#define GCS_TOOLBAR_H

#include <QWidget>
#include <QToolButton>
#include <QButtonGroup>
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QHBoxLayout>
#include <QFile>
#include "ui_gcs_toolbar.h"

namespace Ui {
class GcsToolbar;
}

class GcsToolbar : public QWidget
{
    Q_OBJECT
    Q_ENUMS(Vehicle)

    friend class ToolbarTest;
public:
    explicit GcsToolbar(QWidget *parent = 0);
    enum Vehicle {
        UAV_CPP,
        UAV_CPP2,
        UAV_SLO,
        UGV_CPP,
        UGV_SLO
    };
    QToolButton* getBtnMapView();
    QToolButton* getBtnWaypointContext();
    QToolButton* getBtnZoningContext();
    QToolButton* getBtnPayloadContext();
    QToolButton* getBtnSettings();
    QAction* getVehicleAction(GcsToolbar::Vehicle vid);

private:
    QToolButton *btnMapView;
    QToolButton *btnUavView;
    QToolButton *btnUgvView;
    QToolButton *btnWaypointContext;
    QToolButton *btnZoningContext;
    QToolButton *btnPayloadContext;
    QToolButton *btnSettings;
    QButtonGroup *bgrpViews;
    QButtonGroup *bgrpContexts;
    QAction *actionCppUgv;
    QAction *actionSloUgv;
    QAction *actionCppUav;
    QAction *actionCppUav2;
    QAction *actionSloUav;
    static const int SZ_ICON = 64;
    static const int SZ_BTN_HEIGHT = 67;
    static const int SZ_BTN_WIDTH = 67;
    static const int SZ_HIGHLIGHT = 6;
    static const int SZ_SPACING = 4;
    QSize szIcon;
signals:
    void clickedMapView();
    void clickedUavView(GcsToolbar::Vehicle vehicle);
    void clickedUgvView(GcsToolbar::Vehicle vehicle);
    void clickedPayload();
    void clickedSettings();
    void clickedWaypoints();
    void clickedZoning();

public slots:
    void slotMapView();
    void slotUavViewCpp();
    void slotUavViewSlo();
    void slotUavViewCpp2();
    void slotUgvViewCpp();
    void slotUgvViewSlo();
    void slotPayload();
    void slotSettings();
    void slotWaypoints();
    void slotZoning();

private:
    Ui::GcsToolbar *ui;
};

Q_DECLARE_METATYPE(GcsToolbar::Vehicle);

#endif // GCS_TOOLBAR_H
