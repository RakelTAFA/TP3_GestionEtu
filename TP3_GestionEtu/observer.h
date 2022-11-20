#pragma once
#include <QVector>

/**
 * @brief Class to set up the MVC thanks to the Observer design pattern
 * @author Rakel Tafa
*/

class Observer {
public:
	virtual ~Observer() {}
	virtual void update() = 0;
};

/**
 * @brief Class to set up the MVC thanks to the Observer design pattern
 * @author Rakel Tafa
*/

class Observable {
private:
	QVector<Observer*> observersList;
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyObserver() const;
};
