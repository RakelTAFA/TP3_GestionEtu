#include "viewHistogram.h"
#include <QBarCategoryAxis>
#include <QValueAxis>

ViewHistogram::ViewHistogram(Promotion* p, QChartView* chartViewE, QChartView* pieViewE)
{
	promotion = p;
	chartView = chartViewE;
	pieView = pieViewE;
	update();
}


void ViewHistogram::update() {

	int nbAutres = 0, nbES = 0, nbEtr = 0, nbL = 0, nbS = 0, nbSTG = 0, nbSTI = 0;

	QVector<QBarSet*> set(7, nullptr);

	set[0] = new QBarSet("Autres");
	set[1] = new QBarSet("ES");
	set[2] = new QBarSet("Etr");
	set[3] = new QBarSet("L");
	set[4] = new QBarSet("S");
	set[5] = new QBarSet("STG");
	set[6] = new QBarSet("STI");

	for (auto it : promotion->getstudent_liste()) {
		if (it->getBac() == "Autres") {
			nbAutres++;
		}
		else if (it->getBac() == "ES") {
			nbES++;
		}
		else if (it->getBac() == "Etr") {
			nbEtr++;
		}
		else if (it->getBac() == "L") {
			nbL++;
		}
		else if (it->getBac() == "S") {
			nbS++;
		}
		else if (it->getBac() == "STG") {
			nbSTG++;
		}
		else if (it->getBac() == "STI") {
			nbSTI++;
		}
	}

	QBarSeries* series = new QBarSeries();

	*set[0] << nbAutres;
	*set[1] << nbES;
	*set[2] << nbEtr;
	*set[3] << nbL;
	*set[4] << nbS;
	*set[5] << nbSTG;
	*set[6] << nbSTI;

	for (int i = 0; i < 7; i++) {
		series->append(set[i]);
	}

	QChart* chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Bacs d'origines");
	chart->setAnimationOptions(QChart::SeriesAnimations);

	QStringList categories;
	categories << "Autres" << "ES" << "Etr" << "L" << "S" << "STG" << "STI";
	QBarCategoryAxis* axeX = new QBarCategoryAxis();
	axeX->append(categories);
	//chart->addAxis(axeX, Qt::AlignBottom);
	//series->attachAxis(axeX);

	QValueAxis* axeY = new QValueAxis();
	axeY->setLabelFormat("%d");
	chart->addAxis(axeY, Qt::AlignLeft);
	series->attachAxis(axeY);

	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

	chartView->setChart(chart);
	//chartView->setRenderHint(QPainter::Antialiasing);

	// Pie Chart

	QVector<int> departement_count(97);

	for (auto it : promotion->getstudent_liste()) {
		if (it->getDepartement() == "Autres") {
			departement_count[96]++;
		}
		else {
			++departement_count[it->getDepartement().toInt()];
		}
	}

	/*
	QPieSeries* pieSeries = new QPieSeries();

	for (int i = 1; i < 97; i++) {
		pieSeries->append(to_string(departement_count[i]), departement_count[i]);
	}
	*/

}

