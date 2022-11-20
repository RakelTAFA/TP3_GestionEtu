#pragma once
#include "promotion.h"
#include<QtCharts/qbarseries.h>
#include<QtCharts/qbarset.h>
#include <qchartview.h>

/**
 * @brief Class to manage the barChart View
 * @author Rakel Tafa
*/

class ViewHistogram : public QObject, public Observer
{
	Q_OBJECT

private:
	Promotion* promotion;
	QChartView* chartView;
	

public:
	ViewHistogram(Promotion*, QChartView*);
	void update();
};

