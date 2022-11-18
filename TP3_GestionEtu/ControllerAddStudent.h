#pragma once
#include "AbstractController.h"
#include"promotion.h"

class ControllerAddStudent : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerAddStudent(Promotion* = nullptr);
	void control(QVector<QString> ids);

};