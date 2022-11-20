#pragma once
#include "AbstractController.h"
#include"promotion.h"

/**
 * @brief Class to manage the Controller when a Student must be added
 * @author Rakel Tafa
*/

class ControllerAddStudent : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerAddStudent(Promotion* = nullptr);
	void control(QVector<QString> ids);

};