#pragma once
#include <QVector>

class Observer {
public:
	virtual ~Observer() {}
	virtual void update() = 0;
};

class Observable {
private:
	QVector<Observer*> observersList;
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyObserver() const;
};
