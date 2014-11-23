#include "ugv_state.h"

UGV_state::UGV_state(QWidget *parent) :
    QWidget(parent)
{
    //Initialize and label buttons
    mainLayout = new QGridLayout();
    mainLayout->setMargin( 0 );
    automan = new QPushButton();
    automan->setText("AutoToManual");
    manauto = new QPushButton();
    manauto->setText("ManualToAuto");
    rst = new QPushButton();
    rst->setText("Reset");
    DisableMot = new QPushButton();
    DisableMot->setText("Disable Motor");
    EnableMot = new QPushButton();
    EnableMot->setText("Enable Motor");
    ToggleMot = new QPushButton();
    ToggleMot->setText("Toggle Motor");

    //Add to layout
    mainLayout->addWidget(automan,1,0);
    mainLayout->addWidget(manauto,1,1);
    mainLayout->addWidget(rst,1,2);
    mainLayout->addWidget(DisableMot,2,0);
    mainLayout->addWidget(EnableMot,2,1);
    mainLayout->addWidget(ToggleMot,2,2);

    //Set widget layout
    setLayout( mainLayout );

    //Button connections
    connect(automan,SIGNAL(clicked()),this,SLOT(ATM()));
    connect(manauto,SIGNAL(clicked()),this,SLOT(MTA()));
    connect(rst,SIGNAL(clicked()),this,SLOT(r()));
    connect(DisableMot,SIGNAL(clicked()), this,SLOT(DisableM()));
    connect(EnableMot,SIGNAL(clicked()),this,SLOT(EnableM()));
    connect(ToggleMot,SIGNAL(clicked()),this,SLOT(ToggleM()));
}
/**
 * @brief UGV_state::ATM Emits signal to change from autonomous control to manual control
 */
void UGV_state::ATM() {  emit AutoToManual();}

/**
 * @brief UGV_state::MTA Emits signal to change from manual control to autonomous control
 */
void UGV_state::MTA() {  emit ManualToAuto();}

/**
 * @brief UGV_state::r Emits signal to reset UGV internal logic
 */
void UGV_state::r() { emit Reset(); }

/**
 * @brief UGV_state::DisableM Emits signal to disable UGV motor
 */
void UGV_state::DisableM() {emit DisableMotor(); }

/**
 * @brief UGV_state::EnableM Emits signal to enable UGV motor
 */
void UGV_state::EnableM() {  emit EnableMotor(); }

/**
 * @brief UGV_state::ToggleM Emits signal to toggle current UGV motor's state
 */
void UGV_state::ToggleM() {  emit ToggleMotor(); }
