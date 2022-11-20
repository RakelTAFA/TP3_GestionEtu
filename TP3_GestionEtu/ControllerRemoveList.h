#pragma once
#include "AbstractController.h"
#include"promotion.h"

/**
 * @brief Class to manage the deleting of Students from the List
 * @author Rakel Tafa
*/

class ControllerRemoveList : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerRemoveList(Promotion* = nullptr);
	void control(QVector<QString> ids);

};

