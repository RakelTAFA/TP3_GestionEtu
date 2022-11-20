#include "ControllerRemoveNumber.h"

/**
 * @short	Constructor for ControllerRemoveStudent
 * @param	Promotion*
 * @date    November 2022
 */

ControllerRemoveNumber::ControllerRemoveNumber(Promotion* promotion) : promotion(promotion) {

}

/**
 * @short	Herits from AbstractController. Calls find() from promotion inn order to find a specific Student then calls remove() from promotion
 * @param	QVector<QString>
 * @date    November 2022
 */

void ControllerRemoveNumber::control(QVector<QString> ids) {
	Student* student = promotion->find(ids[0]);

	if (student != nullptr)
		promotion->remove(student);
}