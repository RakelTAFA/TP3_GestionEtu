#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Promotion
    Promotion* promo = new Promotion();
    promo->readList("../data/promoDUT.csv");
    promo->display();

    // Create Interface
    TP3_GestionEtu w(promo);
    w.show();


    return a.exec();
}
