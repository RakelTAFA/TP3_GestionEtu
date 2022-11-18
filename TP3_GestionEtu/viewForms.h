#pragma once
#include "promotion.h"
#include "ControllerRemoveNumber.h"
#include <QLineEdit>
#include <QComboBox>
#include <QObject>
#include "ui_TP3_GestionEtu.h"
#include "ControllerAddStudent.h"


class ViewForms : public QObject {
	Q_OBJECT

public slots:
	void buttonPush();
	void buttonPush2();
public:
	ViewForms(Ui::TP3_GestionEtuClass& ui, Promotion* promotion);
private:
	QLineEdit* identifiant;
	QLineEdit* firstname;
	QLineEdit* lastname;
	QComboBox* bac;
	QComboBox* departement;
	QLineEdit* identifiant2;
	ControllerRemoveNumber controller;
	ControllerAddStudent controller2;
};

