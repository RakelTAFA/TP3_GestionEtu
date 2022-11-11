

class Controller {
	public:
		virtual void controlView() = 0;
};


class ControllerRemoveList : public Controller {
	public:
		void controlView() override;
};


class ControllerForm : public Controller {
	public:
		void controlView() override;
};