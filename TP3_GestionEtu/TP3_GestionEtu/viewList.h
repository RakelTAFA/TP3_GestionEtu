#pragma once
#include "promotion.h"
#include "controller.h"
#include <QListWidget>

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/

class ViewList : public Observer
{
	private:
		Promotion* promotion;
		Controller* controller;
		QListWidget* listWidget;

	public:
		ViewList(Promotion*, QListWidget*);

		Promotion* getPromotion() { return promotion; }

		void update() override;
		void setController(Controller*);

	/*
	private slots:
		void remove(); 
	*/
};