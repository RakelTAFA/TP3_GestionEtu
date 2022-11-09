#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Promotion
    Promotion* promo = new Promotion();
    promo->loadFileCSV(QDir::currentPath() + "/../data/PromoDUT.csv");

    // Create Interface
    TP3_GestionEtu w;
    w.show();



    delete promo;
    return a.exec();
}
