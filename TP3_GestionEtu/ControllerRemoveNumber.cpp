#include "ControllerRemoveNumber.h"

ControllerRemoveNumber::ControllerRemoveNumber(Promotion* promotion) : promotion(promotion) {

}

void ControllerRemoveNumber::control(QVector<QString> ids) {
	Student* student = promotion->find(ids[0]);

	if (student != nullptr)
		promotion->remove(student);
}