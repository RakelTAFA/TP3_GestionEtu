#pragma once
#include "student.h"
#include "observer.h"
#include <QVector>


class Promotion : public Observable
{
private:
	QVector<Student*> student_liste;
public:
	Promotion();
	~Promotion();
	void readList( QString filename);
	void add(Student* etu);
	void display();
	QVector<Student*> getstudent_liste();
	Student* find(QString);
	void remove(Student*);
	//void creaList();
};

