#include "ControllerRemoveList.h"

ControllerRemoveList::ControllerRemoveList(Promotion* promotion): promotion(promotion) {

}

void ControllerRemoveList::control(QVector<QString> ids) {
	for (QString id : ids) {
		Student* student = promotion->find(id);
		if (student != nullptr)
			promotion->remove(student);
	}
}