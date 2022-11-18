#include "observer.h"

void Observable::addObserver(Observer* observer) {
	observersList.append(observer);
}

void Observable::removeObserver(Observer* observer) {
	observersList.removeOne(observer);
}

void Observable::notifyObserver() const {
	for (Observer* observer : observersList)
		observer->update();
}