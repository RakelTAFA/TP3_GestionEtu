#include "viewList.h"


ViewList::ViewList(Promotion* promo) {
	promotion = promo;
	controller = nullptr;
}


void ViewList::setController(Controller* ctrl) {
	if (controller != nullptr) {
		delete controller;
	}
	controller = ctrl;
}


void ViewList::update() {
	/*
	list->clear();
	list->addItem(promo->getList());
	*/

}
