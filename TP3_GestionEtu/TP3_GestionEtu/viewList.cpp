#include "viewList.h"


ViewList::ViewList(Promotion* promo, QListWidget* LW) {
	promotion = promo;
	listWidget = LW;
    update();
}


void ViewList::deleteList() {
    QList<QListWidgetItem*> listSelected = listWidget->selectedItems();
    QList<QString> listeSelectionnee;
    
    for (auto it : listSelected) {
        listeSelectionnee.append(it->text());
    }
    Controller* controller = new ControllerRemoveList(promotion);
    
    controller->controlView(listeSelectionnee);

    delete controller;
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
    cout << "Update effectue" << endl;
}
