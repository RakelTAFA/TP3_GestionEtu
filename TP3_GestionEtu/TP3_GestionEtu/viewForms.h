#pragma once
#include "Observer.h"
#include "controller.h"
#include<qvector.h>
#include<qcombobox.h>

class ViewForms : public Observer, public QObject
{
	private:
		QVector<QWidget*> listLineEdit;

	public:
		ViewForms(QLineEdit*, QLineEdit*, QLineEdit*, QComboBox*, QComboBox*);
		~ViewForms() { ; }

		void update() override;
		void addForm();
};

