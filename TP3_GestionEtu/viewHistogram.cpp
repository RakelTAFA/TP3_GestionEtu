#include "viewHistogram.h"

ViewHistogram::ViewHistogram(Promotion* p) 
{
	promotion = p;
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

	set[0]->append(nbAutres);
	set[1]->append(nbES);
	set[2]->append(nbEtr);
	set[3]->append(nbL);
	set[4]->append(nbS);
	set[5]->append(nbSTG);
	set[6]->append(nbSTI);

	for (int i = 0; i < 7; i++) {
		series->append(set[i]);
	}
}

