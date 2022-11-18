#pragma once
#include "AbstractController.h"
#include"promotion.h"

class ControllerRemoveNumber : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerRemoveNumber(Promotion* = nullptr);
	void control(QVector<QString> ids);

};
