#pragma once
#include "promotion.h"
#include<QtCharts/qpieseries.h>
#include "qchartview.h"


/**
 * @brief Class to manage the PieChart View
 * @author Rakel Tafa
*/

class ViewPieChart  : public Observer
{
	Promotion* promotion;
	QChartView* pieChart;

public:
	ViewPieChart(Promotion* p, QChartView* pChart) : promotion(p), pieChart(pChart) { 
		update();
	}
	void update();
};

