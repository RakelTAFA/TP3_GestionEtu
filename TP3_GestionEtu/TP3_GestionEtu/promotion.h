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

	QVector<Student*> getStudentList() const { return studentList; }
	Student* getStudent(int n) { if (n < studentList.size()) return studentList[n]; }

	void addObserver(Observer*) override;
	void removeObserver(Observer*) override;
	void notifyObservers() const override;

	void addStudent(Student*);
	void deleteStudent(Student*);
	void loadFileCSV(const QString&);
	void displayList();
};

