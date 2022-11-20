#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "promotion.h"

/**
 * @short	Default constructor for Promotion which only creates the instance
 * @date	November 2022
 */

Promotion::Promotion() {
}

/**
 * @short	Destructor for Promotion which deletes all pointers stored into student_liste
 * @date	November 2022
 */

Promotion::~Promotion() {
	for (int i = 0; i < student_liste.count(); i++)
		delete student_liste[i];
}

/**
 * @short	reads the .csv file from the path passed in parameter, and complete the promotion's student_liste with all the students stored in the .csv file 
 * @param	QString
 * @date    November 2022
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

/**
 * @short	Getter for student_liste
 * @return	QVector<Student*>
 * @date    November 2022
 */

QVector<Student*> Promotion::getstudent_liste() {
	return student_liste;
}

/**
 * @short	Used for a terminal display before the graphical implementaion, in order to see if the readList function works correctly
 * @date    November 2022
 */

void Promotion::display() {
	for (Student* pers : getstudent_liste()) {
		qDebug() << pers->getId()<<" "<<pers->getLastname()<<" "<<pers->getFirstname()<<" "<< pers->getDepartement()<<" "<<pers->getBac();
	}
}

/**
 * @short	Finds a Student in student_liste thanks to the ID
 * @param	QString
 * @return	Student*
 * @date    November 2022
 */


Student* Promotion::find(QString id) {
	for (auto pers : getstudent_liste()) {
		if (pers->getId().compare(id)==0)
			return pers;
	}
	return nullptr;
}

/**
 * @short	Herits from Observable. Adds a Student* to student_liste and notifies all Observers from ObserversList contained in Promotion
 * @param	Student*
 * @date    November 2022
 */

void Promotion::add(Student* student) {
	student_liste.push_back(student);
	notifyObserver();
}

/**
 * @short	Herits from Observable. Removes a Student* from student_liste and notifies all Observers from ObserversList contained in Promotion
 * @param	Student*
 * @date    November 2022
 */

void Promotion::remove(Student* student) {
	student_liste.removeOne(student);
	notifyObserver();
}