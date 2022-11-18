#pragma once
#include <QVector>
#include <QString>
class AbstractController
{
public:
	virtual void control(QVector<QString> ids) = 0;
};

