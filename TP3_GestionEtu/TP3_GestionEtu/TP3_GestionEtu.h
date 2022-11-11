#pragma once

#include <QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"

class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    TP3_GestionEtu(QWidget* parent = nullptr);
    ~TP3_GestionEtu() { ; }

    void setViewList(ViewList*);

    void displayListWidget();

    //Ui::TP3_GestionEtuClass getInterface() { return ui; }

private:
    Ui::TP3_GestionEtuClass ui;

    ViewList* listView;
    ViewForms* listForm;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;

    

private slots:
    void deleteList();
};
