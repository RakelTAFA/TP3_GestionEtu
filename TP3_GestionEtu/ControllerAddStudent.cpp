#include "ControllerAddStudent.h"

ControllerAddStudent::ControllerAddStudent(Promotion* promotion) : promotion(promotion) {

}

void ControllerAddStudent::control(QVector<QString> student) {
	promotion->add(new Student(student[0], student[1], student[2], student[3], student[4]));
}
