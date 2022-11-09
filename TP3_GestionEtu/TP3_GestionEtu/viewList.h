#pragma once
#include "promotion.h"
#include <QListWidget>

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public Observer
{
	private:


	public:
		ViewList(Promotion*, QListWidget*);
		void update() override;

	private slots:
		void remove(); 
};

