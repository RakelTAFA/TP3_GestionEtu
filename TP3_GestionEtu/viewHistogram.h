#pragma once
#include "promotion.h"
#include<QtCharts/qbarseries.h>
#include<QtCharts/qbarset.h>

class ViewHistogram : public QObject, public Observer
{
	Q_OBJECT

private:
	Promotion* promotion;


public:
	ViewHistogram(Promotion*);
	void update();
};

