#include "ugv_state.h"

UGV_state::UGV_state(QWidget *parent) :
    QWidget(parent)
{
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
    mainLayout->addWidget(automan,1,0);
    mainLayout->addWidget(manauto,1,1);
    mainLayout->addWidget(rst,1,2);
    mainLayout->addWidget(DisableMot,2,0);
    mainLayout->addWidget(EnableMot,2,1);
    mainLayout->addWidget(ToggleMot,2,2);
    setLayout( mainLayout );
    connect(automan,SIGNAL(clicked()),this,SLOT(ATM()));
    connect(manauto,SIGNAL(clicked()),this,SLOT(MTA()));
    connect(rst,SIGNAL(clicked()),this,SLOT(r()));
    connect(DisableMot,SIGNAL(clicked()), this,SLOT(DisableM()));
    connect(EnableMot,SIGNAL(clicked()),this,SLOT(EnableM()));
    connect(ToggleMot,SIGNAL(clicked()),this,SLOT(ToggleM()));
}

void UGV_state::ATM() {  emit AutoToManual();}

void UGV_state::MTA() {  emit ManualToAuto();}

void UGV_state::r() { emit Reset(); }

void UGV_state::DisableM() {emit DisableMotor(); }

void UGV_state::EnableM() {  emit EnableMotor(); }

void UGV_state::ToggleM() {  emit ToggleMotor(); }
