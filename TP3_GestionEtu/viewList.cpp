#include "viewList.h"


ViewList::ViewList(QListWidget * listWidget, Promotion * promotion) {
	this->listWidget = listWidget;
	this->promotion = promotion;
	this->controller = ControllerRemoveList(promotion);

	update();
}

void ViewList::update() {
	listWidget->clear();
	for (auto pers : promotion->getstudent_liste()) {
		listWidget->addItem(pers->getId() + " - " + pers->getLastname() + " " + pers->getFirstname() + " (" + pers->getDepartement() + ")");
	}
}

void ViewList::buttonPush() {
	QStringList	items;
	for (QListWidgetItem* listWidget : listWidget->selectedItems())
		items.append(listWidget->text().split(" ")[0]);
	controller.control(items);
	
}