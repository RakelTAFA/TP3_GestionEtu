#include "viewList.h"

/**
 * @short	Constructor for ViewList; Takes the listWidget from the ui as parameter. Calls update() to initialize the list on the GUI
 * @param	QListWidget*
 * @date	November 2022
 */

ViewList::ViewList(QListWidget * listWidget, Promotion * promotion) {
	this->listWidget = listWidget;
	this->promotion = promotion;
	this->controller = ControllerRemoveList(promotion);

	update();
}

/**
 * @short	Initialize the GUI with the promotion's content
 * @date	November 2022
 */

void ViewList::update() {
	listWidget->clear();
	for (auto pers : promotion->getstudent_liste()) {
		listWidget->addItem(pers->getId() + " - " + pers->getLastname() + " " + pers->getFirstname() + " (" + pers->getDepartement() + ")");
	}
}

/**
 * @short	Method for the connect, in order to create the list of selected items. Creates a controller for the list.
 * @param	Promotion*, QChartView*
 * @date	November 2022
 */

void ViewList::buttonPush() {
	QStringList	items;
	for (QListWidgetItem* listWidget : listWidget->selectedItems())
		items.append(listWidget->text().split(" ")[0]);
	controller.control(items);
	
}