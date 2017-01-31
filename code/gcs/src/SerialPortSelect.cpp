#include "SerialPortSelect.h"

SerialPortSelect::SerialPortSelect(QWidget *parent) : QWidget(parent){
    combo = new SerialComboBox();
    combo->setAutoCompletion(false);
    combo->setEditable(false);
    combo->setFont(QFont("Courier New"));

    //Listen to the combo box for an index selection changed
    connect(combo, SIGNAL(currentIndexChanged(const QString&)),
            this, SLOT(indexChanged(const QString&)));

    mainLayout = new QGridLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setVerticalSpacing(0);
    mainLayout->setHorizontalSpacing(0);
    mainLayout->addWidget(combo,0,0);
    setLayout(mainLayout);
}

void SerialPortSelect::indexChanged(const QString& text){
    //Make sure we don't emit a signal when the user populates the combobox
    if(text != ""){
        emit serialPortSelected(text);
    }
}

SerialPortSelect::~SerialPortSelect()
{
    combo = NULL;
    delete combo;
    mainLayout = NULL;
    delete mainLayout;
}
