#include "viewPieChart.h"
#include <qpieseries.h>

/**
 * @short	Method which herits from Observer. Initializes the GUI with the correct PieChart in function of the Promotion's Student list
 * @date	November 2022
 */

void ViewPieChart::update()
{
	QVector<int> departement_count(97);

	for (auto it : promotion->getstudent_liste()) {
		if (it->getDepartement() == "Autres") {
			departement_count[96]++;
		}
		else {
			++departement_count[it->getDepartement().toInt()];
		}
	}


	QPieSeries* pieSeries = new QPieSeries();

	for (int i = 1; i < 97; i++) {
		if (departement_count[i] > 0) {
			if (i != 96) {
				QString value = std::to_string(i).c_str();
				pieSeries->append(value, departement_count[i]);
			}
			else {
				pieSeries->append("Autres", departement_count[i]);
			}
		}	
	}

	QChart* chartPie = new QChart();
	chartPie->addSeries(pieSeries);
	chartPie->setTitle("Departements");
	chartPie->setAnimationOptions(QChart::SeriesAnimations);

	//QChartView* chartViewPie = new QChartView(chartPie);
	//chartViewPie->setRenderHint(QPainter::Antialiasing);

	pieChart->setChart(chartPie);
}
