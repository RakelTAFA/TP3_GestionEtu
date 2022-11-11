#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(ViewList* viewList, QWidget *parent)
    : QMainWindow(parent)
{
    listView = viewList;
    
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
        int size = listView->getPromotion()->getStudentList().size();
        for (int i = 0; i < size; i++) {
            ui.listWidget.addItem(listView->getPromotion()->getStudentList());
        }
    }
}


void TP3_GestionEtu::deleteList() {
    cout << "Pressed" << endl;
}