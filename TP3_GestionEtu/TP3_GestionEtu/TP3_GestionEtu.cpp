#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* promo, QWidget *parent)
    : promotion(promo), QMainWindow(parent), listForm(nullptr), pieChartView(nullptr), histogramView(nullptr)
{
    ui.setupUi(this);
    
    listView = new ViewList(promo, ui.listWidget);
    promo->addObserver(listView);
    
    connect(ui.pushButton_delete_list, &QPushButton::pressed, listView, &ViewList::deleteList);
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
