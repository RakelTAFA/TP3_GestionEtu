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
}


void Promotion::addObserver(Observer* observer) {
	return;
}


void Promotion::removeObserver(Observer* observer) {
	return;
}


void Promotion::notifyObserver() const {
	return;
}


void Promotion::addStudent(Student* student) {
	studentList.push_back(student);
}


void Promotion::deleteStudent(Student* student) {
	size_t taille = studentList.size();
	for (size_t i = 0; i < taille; i++) {
		if (student == studentList[i]) {
			studentList.remove(i);
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
