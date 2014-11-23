#include "commsgui.h"
#include "ui_commsgui.h"

CommsGUI::CommsGUI(QWidget *parent) :
    QWidget(parent)
{
    /** Vechical display panel*/
    altNum = new QLabel("0.0 ",this);
    altNum -> setGeometry(QRect(QPoint(140,50), QSize(50,50)));

    altNum2 = new QLabel("0.0 ",this);
    altNum2 -> setGeometry(QRect(QPoint(140,110), QSize(50,50)));

    altNum3 = new QLabel("0.0 ",this);
    altNum3 -> setGeometry(QRect(QPoint(140,170), QSize(50,50)));

    altNum4 = new QLabel("0.0 ",this);
    altNum4 -> setGeometry(QRect(QPoint(140,225), QSize(50,50)));

    spdNum = new QLabel("0.0 ",this);
    spdNum -> setGeometry(QRect(QPoint(195,50), QSize(50,50)));

    spdNum2 = new QLabel("0.0 ",this);
    spdNum2 -> setGeometry(QRect(QPoint(195,110), QSize(50,50)));

    spdNum3 = new QLabel("0.0 ",this);
    spdNum3 -> setGeometry(QRect(QPoint(195,170), QSize(50,50)));

    spdNum4 = new QLabel("0.0 ",this);
    spdNum4 -> setGeometry(QRect(QPoint(195,225), QSize(50,50)));

    /** Comms system check layout*/
    QHBoxLayout *sysCheck = new QHBoxLayout;
    sysCheck->addWidget(createCommsBoxGroup());
    sysCheck->addWidget(createToggleGroup());
    setLayout(sysCheck);

    resize(480, 320);
}

QGroupBox *CommsGUI::createCommsBoxGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Vechical Status              Altitude      Speed"));

    //This group box contains only checkboxes, so it is non-exclusive by default.
    //This means that each checkbox can be checked independently of the others.
    QCheckBox *checkBox1 = new QCheckBox(tr("Vechical 1 status: "));
    QCheckBox *checkBox2 = new QCheckBox(tr("Vechical 2 status: "));
    QCheckBox *checkBox3 = new QCheckBox(tr("Vechical 3 status: "));
    QCheckBox *checkBox4 = new QCheckBox(tr("Vechical 4 status: "));

    //Use a vertical layout within the group box to present the buttons in the form of a vertical list.
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(checkBox1);
    vbox->addWidget(checkBox2);
    vbox->addWidget(checkBox3);
    vbox->addWidget(checkBox4);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *CommsGUI::createToggleGroup()
{
    //The first group box contains and manages three radio buttons.
    //Since the group box contains only radio buttons, it is exclusive by default,
    //so only one radio button can be checked at any given time.
    //We check the first radio button to ensure that the button group contains one checked button.
    QGroupBox *groupBox = new QGroupBox(tr("Comms Buttons"));
    QRadioButton *radio1 = new QRadioButton(tr("Comms Operational"));
    QRadioButton *radio2 = new QRadioButton(tr("Comms Operational"));
    QRadioButton *radio3 = new QRadioButton(tr("Comms Operational"));
    QRadioButton *radio4 = new QRadioButton(tr("Comms Operational"));

    radio2->setChecked(true);
    radio3->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    groupBox->setLayout(vbox);

    return groupBox;
}

CommsGUI::~CommsGUI()
{
    //no Forms
}
