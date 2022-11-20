#include "ControllerRemoveList.h"

/**
 * @short	Constructor for ControllerRemoveList
 * @param	Promotion*
 * @date    November 2022
 */

ControllerRemoveList::ControllerRemoveList(Promotion* promotion): promotion(promotion) {

}

/**
 * @short	Herits from AbstractController. For each selected Student on the list, it calls remove from Promotion
 * @param	QVector<QString>
 * @date    November 2022
 */

void ControllerRemoveList::control(QVector<QString> ids) {
	for (QString id : ids) {
		Student* student = promotion->find(id);
		if (student != nullptr)
			promotion->remove(student);
	}
}