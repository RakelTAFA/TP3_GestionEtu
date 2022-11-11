#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(QWidget *parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);

    connect(ui.pushButton_delete_list, &QPushButton::released, this, &TP3_GestionEtu::deleteList);
}


void TP3_GestionEtu::setViewList(ViewList* VL) {
    if (listView != nullptr) {
        delete listView;
    }
    listView = VL;
}


void TP3_GestionEtu::displayListWidget() {
    if (listView != nullptr) {
        string num;
        QString listString;
        QListWidget* list = ui.listWidget;
        int size = listView->getPromotion()->getStudentList().size();
        
        for (int i = 0; i < size; i++) {
            num = to_string(listView->getPromotion()->getStudentList()[i]->getNumero());
            listString = QString::fromStdString(num);
            listString += " - " + listView->getPromotion()->getStudentList()[i]->getPrenom();
            listString += " " + listView->getPromotion()->getStudentList()[i]->getNom();
            listString += " (" + listView->getPromotion()->getStudentList()[i]->getDepartement() + ")";
            list->addItem(listString);
        }
    }
}


void TP3_GestionEtu::deleteList() {
    
    
    //listView->getPromotion()->notifyObservers();
}