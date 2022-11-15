#pragma once
#include "Observer.h"
#include "controller.h"
#include<qvector.h>

class ViewForms : public Observer, public QObject
{
	private:
		QVector<QWidget*> listLineEdit;

	public:
		ViewForms();
		~ViewForms() { ; }

		void update() override;
		void addForm();
};

