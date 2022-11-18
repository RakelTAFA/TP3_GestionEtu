#include "viewForms.h"

ViewForms::ViewForms(Ui::TP3_GestionEtuClass& ui, Promotion* promotion)
{
	identifiant=ui.lineEdit_add_number;
	firstname=ui.lineEdit_add_firstname;
	lastname=ui.lineEdit_add_lastname;
	identifiant2=ui.lineEdit_remove_number;
	bac=ui.lineEdit_add_BAC;
	departement=ui.lineEdit_add_department;

	this->controller = ControllerRemoveNumber(promotion);
	this->controller2 = ControllerAddStudent(promotion);
}


void ViewForms::buttonPush() {
	QVector<QString> list;

	list.push_back(identifiant2->text());
	controller.control(list);

}


void ViewForms::buttonPush2() {
	QVector<QString> list;

	list.push_back(identifiant->text());
	list.push_back(firstname->text());
	list.push_back(lastname->text());
	list.push_back(bac->currentText());
	list.push_back(departement->currentText());

	controller2.control(list);
}