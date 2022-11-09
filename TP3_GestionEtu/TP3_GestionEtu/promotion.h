#pragma once
#include<qvector>
#include "Student.h"
#include"observer.h"


class Promotion : public Observable
{
	QVector<Observer*> observerList;
	QVector<Student*> studentList;

public:
	Promotion();
	~Promotion();

	void addObserver(Observer*) override;
	void removeObserver(Observer*) override;
	void notifyObserver() const override;

	void addStudent(Student*);
	void deleteStudent(Student*);
	void loadFileCSV(const QString&);
	void displayList();
};

