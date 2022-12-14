#pragma once


class Observer {
public:
  virtual ~Observer() {}
  virtual void update() = 0;
};

class Observable {
public:
  virtual ~Observable() {}
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObservers() const = 0;
};
