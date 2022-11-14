#include "controller.h"


ControllerRemoveList::ControllerRemoveList(Promotion* p) {
	promo = p;
}


void ControllerRemoveList::controlView(QList<QString> liste) {
	
	for (auto it : liste) {
		auto tmp = it.split(' ');
		promo->deleteStudent(tmp[0].toInt());
	}
}


void ControllerForm::controlView(QList<QString>) {

}