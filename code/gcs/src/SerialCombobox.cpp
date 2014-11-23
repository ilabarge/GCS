#include "SerialCombobox.h"

SerialComboBox::SerialComboBox(QWidget* parent) : QComboBox(parent)
{
    this->setMinimumHeight(20);
    this->setMinimumWidth(100);
}

/**
 * @brief SerialPortSelect::mousePressEvent
 * Filter of the mousePressEvent on the ComboBox
 *
 * @param event
 */
void SerialComboBox::mousePressEvent(QMouseEvent *event){
    switch(event->type()){
        case event->MouseButtonPress:
            updateList();
            break;
        default:
            //Do nothing
            break;
    }
    QComboBox::mousePressEvent(event); //Pass onto QComboBox itself.
}

void SerialComboBox::updateList(){
    this->clear();
    //Create serial port scanner
    serialScanner *scanner = new serialScanner();
    //Get list of serial ports
    QStringList serialPortList;
    serialPortList << "" << scanner->ports();

    if(serialPortList.length() == 0){
        //Notify user
    }
    else{
        //Create Iterator list for ports
        QListIterator<QString> serialListIterator(serialPortList);

        for(int i = 0; serialListIterator.hasNext(); i++){
            QString portValue = serialListIterator.next();

            this->addItem(portValue, portValue);
//            portList->at(i) = portValue;
        }
    }
    delete scanner; //Clean up what we're not using anymore
}

SerialComboBox::~SerialComboBox(){

}
