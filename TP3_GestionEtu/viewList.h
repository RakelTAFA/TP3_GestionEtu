#pragma once
#include "observer.h"
#include "promotion.h"
#include "ControllerRemoveList.h"
#include <QListWidget>
#include <QObject>

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public QObject, public Observer {
	Q_OBJECT

public slots:
	void buttonPush();
private:
	QListWidget* listWidget;
	Promotion* promotion;
	ControllerRemoveList controller;
public:
	ViewList(QListWidget* = nullptr, Promotion* = nullptr);
	void update();
};


