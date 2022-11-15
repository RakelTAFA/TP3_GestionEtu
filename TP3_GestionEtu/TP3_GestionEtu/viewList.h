#pragma once
#include "promotion.h"
#include "controller.h"
#include <QListWidget>

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/

class ViewList : public Observer, public QObject
{
	private:
		Promotion* promotion;
		QListWidget* listWidget;

	public:
		ViewList(Promotion*, QListWidget*);
		~ViewList();
		
		void deleteList();

		//Promotion* getPromotion() { return promotion; }

		void update() override;
};