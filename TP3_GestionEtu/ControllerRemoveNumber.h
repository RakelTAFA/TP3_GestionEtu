#pragma once
#include "AbstractController.h"
#include"promotion.h"

/**
 * @brief Class to manage the deleting of one Student by its ID
 * @author Rakel Tafa
*/

class ControllerRemoveNumber : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerRemoveNumber(Promotion* = nullptr);
	void control(QVector<QString> ids);

};
