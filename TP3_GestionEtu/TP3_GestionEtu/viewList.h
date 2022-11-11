#pragma once
#include "promotion.h"
#include "controller.h"
#include<qlistwidget.h>

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public Observer
{
	private:
		Promotion* promotion;
		Controller* controller;

	public:
		ViewList(Promotion*);

		Promotion* getPromotion() { return promotion; }

		void update() override;
		void setController(Controller*);

	/*
	private slots:
		void remove(); 
	*/
};

