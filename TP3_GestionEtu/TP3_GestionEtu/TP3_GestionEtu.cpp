#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* promo, QWidget *parent)
    : promotion(promo), QMainWindow(parent), listForm(nullptr), pieChartView(nullptr), histogramView(nullptr)
{
    ui.setupUi(this);
    
    listView = new ViewList(promo, ui.listWidget);
    promo->addObserver(listView);

    constructDepartmentItem();

    listForm = new ViewForms();
    promo->addObserver(listForm);
    
    connect(ui.pushButton_delete_list, &QPushButton::pressed, listView, &ViewList::deleteList);
    connect(ui.pushButton_addStudent, &QPushButton::pressed, listForm, &ViewForms::addForm);
}


void TP3_GestionEtu::constructDepartmentItem()
{
    QString item;
    for (int i = 1; i <= 95; i++) {
        if (i < 10) {
            item = "0";
            item.append(QString::number(i));
        }
        else {
            item.append(QString::number(i));
        }
        ui.lineEdit_add_department->addItem(item);
        item = "";
    }
}



TP3_GestionEtu::~TP3_GestionEtu() {
    if (listView != nullptr) {
        delete listView;
    }
    if (listForm != nullptr) {
        delete listForm;
    }
    if (pieChartView != nullptr) {
        delete pieChartView;
    }
    if (histogramView != nullptr) {
        delete histogramView;
    }
}


void TP3_GestionEtu::setViewList(ViewList* VL) {
    if (listView != nullptr) {
        delete listView;
    }
    listView = VL;
}




/*
void TP3_GestionEtu::deleteList() {
    QVector<QListWidgetItem*> list = ui.listWidget->selectedItems();
    listView->deleteList();
}
*/
