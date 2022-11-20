#include "viewForms.h"

/**
 * @short	Constructor for ViewForms. Sets the ui widget input fields of the "Form part" memory addresses to the ViewForms which handles them
 * @param	Ui::TP3_GestionEtuClass&, Promotion*
 * @date    November 2022
 */

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

/**
 * @short	Method for the connect part  in order to delete a Student thanks to its ID. Creates the list for completed fiels and sends it to a new dynamically allocated Controller
 * @date    November 2022
 */

void ViewForms::buttonPush() {
	QVector<QString> list;

	list.push_back(identifiant2->text());
	controller.control(list);
}


/**
 * @short	Method for the connect part, in order to add a new Student. Creates the list for completed fiels and sends it to a new dynamically allocated Controller
 * @date    November 2022
 */


void ViewForms::buttonPush2() {
	QVector<QString> list;

	list.push_back(identifiant->text());
	list.push_back(firstname->text());
	list.push_back(lastname->text());
	list.push_back(bac->currentText());
	list.push_back(departement->currentText());

	controller2.control(list);
}