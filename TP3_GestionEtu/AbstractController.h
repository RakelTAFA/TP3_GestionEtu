#pragma once
#include <QVector>
#include <QString>

/**
 * @brief Abstract class to set up the MVC, here is the Contoller part
 * @author Rakel Tafa
*/

class AbstractController
{
public:
	virtual void control(QVector<QString> ids) = 0;
};

