#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(QWidget *parent)
    : QMainWindow(parent)
{
    //listView = nullptr;
    //listForm = nullptr;
    //pieChartView = nullptr;
    //histogramView = nullptr;
    ui.setupUi(this);

    connect(ui.pushButton_delete_list, &QPushButton::released, this, &TP3_GestionEtu::deleteList);
}


void TP3_GestionEtu::deleteList() {
    cout << "Pressed" << endl;
}