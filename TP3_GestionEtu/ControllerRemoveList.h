#pragma once
#include "AbstractController.h"
#include"promotion.h"

class ControllerRemoveList : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerRemoveList(Promotion* = nullptr);
	void control(QVector<QString> ids);

};

