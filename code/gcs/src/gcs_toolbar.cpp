#include "gcs_toolbar.h"

GcsToolbar::GcsToolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GcsToolbar)
{
    ui->setupUi(this);
    szIcon = QSize(SZ_ICON, SZ_ICON);
    QWidget *container = new QWidget;
    // build buttons
    bgrpViews = new QButtonGroup;
    bgrpContexts = new QButtonGroup;
    btnMapView = new QToolButton(this);
    btnMapView->setObjectName("btnMap");
    btnMapView->setIcon(QIcon(":/images/map_icon.png"));
    btnUavView = new QToolButton(this);
    btnUavView->setIcon(QIcon(":/images/uav_icon.png"));
    btnUgvView = new QToolButton(this);
    btnUgvView->setIcon(QIcon(":/images/ugv_icon.png"));
    btnWaypointContext = new QToolButton(this);
    btnWaypointContext->setIcon(QIcon(":/images/waypoint_icon.png"));
    btnZoningContext = new QToolButton(this);
    btnZoningContext->setIcon(QIcon(":/images/zone_icon.png"));
    btnPayloadContext = new QToolButton(this);
    btnPayloadContext->setIcon(QIcon(":/images/payload_icon.png"));
    btnSettings = new QToolButton(this);
    btnSettings->setIcon(QIcon(":/images/settings_icon.png"));
    bgrpViews->addButton(btnMapView);
    bgrpViews->addButton(btnUavView);
    bgrpViews->addButton(btnUgvView);
    bgrpContexts->addButton(btnWaypointContext);
    bgrpContexts->addButton(btnZoningContext);
    bgrpContexts->addButton(btnPayloadContext);

    // organize buttons
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(QMargins(0,0,0,0));
    layout->setSpacing(0);
    for (int i = 0; i < bgrpViews->buttons().size(); i++) {
        layout->addWidget(bgrpViews->buttons().at(i));
        bgrpViews->buttons().at(i)->setIconSize(QSize(64, 64));
        bgrpViews->buttons().at(i)->setCheckable(true);
        ((QToolButton*)bgrpViews->buttons().at(i))->setToolButtonStyle(Qt::ToolButtonIconOnly);
    }
    for (int i = 0; i < bgrpContexts->buttons().size(); i++) {
        layout->addWidget(bgrpContexts->buttons().at(i));
        bgrpContexts->buttons().at(i)->setIconSize(QSize(64, 64));
        bgrpContexts->buttons().at(i)->setCheckable(true);
        ((QToolButton*)bgrpContexts->buttons().at(i))->setToolButtonStyle(Qt::ToolButtonIconOnly);
    }
    layout->addWidget(btnSettings);
    btnSettings->setIconSize(szIcon);
    btnSettings->setToolButtonStyle(Qt::ToolButtonIconOnly);
    container->setLayout(layout);
    container->setObjectName("container");
    container->setFixedHeight(SZ_BTN_HEIGHT + SZ_HIGHLIGHT + 2*SZ_SPACING);
    int toolbarWidth = layout->count()*SZ_BTN_WIDTH + (layout->count() + 1)*SZ_SPACING;
    container->setFixedWidth(toolbarWidth);
    QVBoxLayout *containerLayout = new QVBoxLayout();
    containerLayout->addWidget(container);
    containerLayout->setContentsMargins(QMargins(0,0,0,0));
    this->setLayout(containerLayout);

    // build UAV dropdown
    actionCppUav = this->findChild<QAction*>("actionCPP_UAV");
    actionCppUav2 = this->findChild<QAction*>("actionCPP_UAV2");
    actionSloUav = this->findChild<QAction*>("actionSLO_UAV");
    QMenu *menuUav = new QMenu("UAV View");
    menuUav->addAction(actionCppUav);
    menuUav->addAction(actionCppUav2);
    menuUav->addAction(actionSloUav);
    btnUavView->setMenu(menuUav);
    btnUavView->setPopupMode(QToolButton::InstantPopup);

    // build UGV dropdown
    actionCppUgv = this->findChild<QAction*>("actionCPP_UGV");
    actionSloUgv = this->findChild<QAction*>("actionSLO_UGV");
    QMenu *menuUgv = new QMenu("UGV View");
    menuUgv->addAction(actionCppUgv);
    menuUgv->addAction(actionSloUgv);
    btnUgvView->setMenu(menuUgv);
    btnUgvView->setPopupMode(QToolButton::InstantPopup);

    // custom signals
    connect(btnMapView, SIGNAL(clicked()), this, SLOT(slotMapView()));
    connect(actionCppUav, SIGNAL(triggered()), this, SLOT(slotUavViewCpp()));
    connect(actionCppUav2, SIGNAL(triggered()), this, SLOT(slotUavViewCpp2()));
    connect(actionSloUav, SIGNAL(triggered()), this, SLOT(slotUavViewSlo()));
    connect(actionCppUgv, SIGNAL(triggered()), this, SLOT(slotUgvViewCpp()));
    connect(actionSloUgv, SIGNAL(triggered()), this, SLOT(slotUgvViewSlo()));
    connect(btnWaypointContext, SIGNAL(clicked()), this, SLOT(slotWaypoints()));
    connect(btnPayloadContext, SIGNAL(clicked()), this, SLOT(slotPayload()));
    connect(btnZoningContext, SIGNAL(clicked()), this, SLOT(slotZoning()));
    connect(btnSettings, SIGNAL(clicked()), this, SLOT(slotSettings()));

    // custom style
    QFile styleFile(":/style/toolbar.qss");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    style.replace(QString("%SZ_HIGHLIGHT%"), QString::number(SZ_HIGHLIGHT));
    style.replace(QString("%SZ_ICON%"), QString::number(SZ_ICON));
    style.replace(QString("%SZ_SPACING%"), QString::number(SZ_SPACING));
    this->setStyleSheet(style);
}

void GcsToolbar::slotMapView() {
    emit clickedMapView();
}

void GcsToolbar::slotUavViewCpp() {
    btnUavView->setChecked(true);
    emit clickedUavView(GcsToolbar::UAV_CPP);
}

void GcsToolbar::slotUavViewCpp2() {
    btnUavView->setChecked(true);
    emit clickedUavView(GcsToolbar::UAV_CPP2);
}

void GcsToolbar::slotUavViewSlo() {
    btnUavView->setChecked(true);
    emit clickedUavView(GcsToolbar::UAV_SLO);
}

void GcsToolbar::slotUgvViewCpp() {
    btnUgvView->setChecked(true);
    emit clickedUgvView(GcsToolbar::UGV_CPP);
}

void GcsToolbar::slotUgvViewSlo() {
    btnUgvView->setChecked(true);
    emit clickedUgvView(GcsToolbar::UGV_SLO);
}

void GcsToolbar::slotPayload() {
    emit clickedPayload();
}

void GcsToolbar::slotSettings() {
    emit clickedSettings();
}

void GcsToolbar::slotWaypoints() {
    emit clickedWaypoints();
}

void GcsToolbar::slotZoning() {
    emit clickedZoning();
}

QToolButton* GcsToolbar::getBtnMapView() {
    return btnMapView;
}
QToolButton* GcsToolbar::getBtnWaypointContext() {
    return btnWaypointContext;
}
QToolButton* GcsToolbar::getBtnZoningContext() {
    return btnZoningContext;
}
QToolButton* GcsToolbar::getBtnPayloadContext() {
    return btnPayloadContext;
}
QToolButton* GcsToolbar::getBtnSettings() {
    return btnSettings;
}
QAction* GcsToolbar::getVehicleAction(GcsToolbar::Vehicle vid) {
    switch(vid) {
        case GcsToolbar::UAV_CPP:
            return actionCppUav;
        case GcsToolbar::UAV_CPP2:
            return actionCppUav2;
        case GcsToolbar::UAV_SLO:
            return actionSloUav;
        case GcsToolbar::UGV_CPP:
            return actionCppUgv;
        case GcsToolbar::UGV_SLO:
            return actionSloUgv;
        default:
            return NULL;
    }
}
