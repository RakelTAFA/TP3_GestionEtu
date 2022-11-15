#include "promotion.h"
#include<qfile>
#include<qtextstream>
#include<qdebug>

Promotion::Promotion() {

}


Promotion::~Promotion() {
	Q_FOREACH(Student* st, studentList) {
		delete st;
	}
	Q_FOREACH(Observer* obs, observerList) {
		delete obs;
	}
}


void Promotion::addObserver(Observer* observer) {
	observerList.push_back(observer);
}


void Promotion::removeObserver(Observer* observer) {
	size_t size = observerList.size();
	for (size_t i = 0; i < size; i++) {
		if (observer == observerList[i]) {
			observerList.remove(i);
			return;
		}
	}
}


void Promotion::notifyObservers() const {
	for (auto it : observerList) {
		it->update();
	}
}


void Promotion::addStudent(Student* student) {
	studentList.push_back(student);
}


void Promotion::deleteStudent(int num) {
	size_t taille = studentList.size();
	for (size_t i = 0; i < taille; i++) {
		if (studentList[i]->getNumero() == num) {
			studentList.removeAt(i);
			notifyObservers();
			return;
		}
	}
}


void Promotion::loadFileCSV(const QString& filePath) {

	QString buffer;

	QFile file(filePath);
	if (file.open(QIODevice::ReadOnly | QFile::Text)) {
		QTextStream fileIn(&file);

		int num;
		QString prenom, nom, bac, dpt;

		while (!fileIn.atEnd()) {
			buffer = fileIn.readLine();

			if (buffer != "") {
				QStringList liste = buffer.split(';');
				num = liste[0].toInt();
				nom = liste[1];
				prenom = liste[2];
				dpt = liste[3];
				bac = liste[4];

				addStudent(new Student(num, prenom, nom, bac, dpt));
			}
		}
	}
	else {
		qDebug() << "Unable to open file " << filePath << " : error " << file.error() << ", " << file.errorString();
	}
}


void Promotion::displayList() {
	for (auto it : studentList) {
		cout << it->getNumero() << " " << it->getPrenom().toStdString() << " " << it->getNom().toStdString() << " " << it->getBac().toStdString() << " " << it->getDepartement().toStdString() << endl;
	}
}
