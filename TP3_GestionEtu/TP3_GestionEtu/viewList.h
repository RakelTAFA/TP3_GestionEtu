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
		Controller* controller;

	public:
		ViewList(Promotion*, QListWidget*);

		void update() override;
		void setController(Controller*);

	/*
	private slots:
		void remove(); 
	*/
};

