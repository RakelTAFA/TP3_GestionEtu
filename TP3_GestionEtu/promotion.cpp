#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "promotion.h"

Promotion::Promotion() {
}

Promotion::~Promotion() {
	for (int i = 0; i < student_liste.count(); i++)
		delete student_liste[i];
}


/**
 * @brief       Fonction permettant l'initialisation et la lecture du fichier passe en parametre 
 * @details     Ici fichier promoDUT.csv de passe en parametre. La fonction utilise les fonction de lecture de fichier de QT avec QTextStream, QStringList et la propriete split.
 * @author      Gael JOURNET & Jean-Francois MARCOURT
 * @date        novembre 2022
 */
void Promotion::readList( QString url)
{
	QFile file(url);

	if (file.open(QIODevice::ReadOnly | QFile::Text)){
		QTextStream in(&file);
		QString id, ln, fn, b, dep;
		while (!in.atEnd())
		{
			QStringList split = in.readLine().split(';');
			add(new Student(split[0], split[1], split[2], split[3], split[4]));
		}
		file.close();
	}
	else {
		qDebug() << "Open file Error, URL : " << url << "\n";
	}


}

QVector<Student*> Promotion::getstudent_liste() {
	return student_liste;
}

void Promotion::display() {
	for (Student* pers : getstudent_liste()) {
		qDebug() << pers->getId()<<" "<<pers->getLastname()<<" "<<pers->getFirstname()<<" "<< pers->getDepartement()<<" "<<pers->getBac();
	}
}


Student* Promotion::find(QString id) {
	for (auto pers : getstudent_liste()) {
		if (pers->getId().compare(id)==0)
			return pers;
	}
	return nullptr;
}

void Promotion::add(Student* student) {
	student_liste.append(student);
	notifyObserver();
}

void Promotion::remove(Student* student) {
	student_liste.removeOne(student);
	notifyObserver();
}