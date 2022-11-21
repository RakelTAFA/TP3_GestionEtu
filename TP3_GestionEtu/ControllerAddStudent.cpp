#include "ControllerAddStudent.h"

/**
 * @short	Constructor for ControllerAddStudent
 * @param	Promotion*
 * @date    November 2022
 */

ControllerAddStudent::ControllerAddStudent(Promotion* promotion) : promotion(promotion) {

}

/**
 * @short	Herits from AbstractController. It calls add() from the promotion attribute.
 * @param	QVector<QString>
 * @date    November 2022
 */

void ControllerAddStudent::control(QVector<QString> student) {
	promotion->add(new Student(student[0], student[1], student[2], student[4], student[3]));
}
