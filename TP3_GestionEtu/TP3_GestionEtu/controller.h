#include<qlistwidget.h>
#include"promotion.h"

class Controller {
	public:
		virtual void controlView(QList<QString>) = 0;
	
	protected:
		Promotion* promo;
};


class ControllerRemoveList : public Controller {
	
	public:
		ControllerRemoveList(Promotion*);
		void controlView(QList<QString>) override;
};


class ControllerForm : public Controller {
	public:
		void controlView(QList<QString>) override;
};