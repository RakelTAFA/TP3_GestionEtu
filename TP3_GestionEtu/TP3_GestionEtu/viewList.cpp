#include "viewList.h"


ViewList::ViewList(Promotion* promo, QListWidget* LW) {
	promotion = promo;
	listWidget = LW;
	controller = nullptr;
}


void ViewList::setController(Controller* ctrl) {
	if (controller != nullptr) {
		delete controller;
	}
	controller = ctrl;
}


void ViewList::update() {
	
	listWidget->clear();
    string num;
    QString listString;
	int size = promotion->getStudentList().size();

    for (int i = 0; i < size; i++) {
        num = to_string(promotion->getStudentList()[i]->getNumero());
        listString = QString::fromStdString(num);
        listString += " - " + promotion->getStudentList()[i]->getPrenom();
        listString += " " + promotion->getStudentList()[i]->getNom();
        listString += " (" + promotion->getStudentList()[i]->getDepartement() + ")";
        listWidget->addItem(listString);
    }
    
    cout << "Update effectué" << endl;

}
