#pragma once

#include "ICommand.h"

class InputHandler {
public:
	ICommand* HandleInput();

	void AssingMoveLeftCommand2PreesKeyA();
	void AssingMoveRightCommand2PreesKeyD();

private:
	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
};
