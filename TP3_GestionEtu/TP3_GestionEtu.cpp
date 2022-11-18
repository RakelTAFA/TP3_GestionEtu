#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* promotion, QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    for (int i = 1; i <= 95; i++) {
        ui.lineEdit_add_department->addItem(QString::number(i).rightJustified(2, '0'));
    }
    ui.lineEdit_add_department->addItem("Autres");

    this->listView = new ViewList(ui.listWidget, promotion);
    this->listForm = new ViewForms(ui, promotion);
    
    promotion->addObserver(listView);

    this->histogramView = new ViewHistogram(promotion);
    promotion->addObserver(histogramView);

    connect(ui.pushButton_delete_list, &QPushButton::released, this->listView, &ViewList::buttonPush);
    connect(ui.pushButton_delete_number, &QPushButton::released, this->listForm, &ViewForms::buttonPush);
    connect(ui.pushButton_addStudent, &QPushButton::released, this->listForm, &ViewForms::buttonPush2);
}
