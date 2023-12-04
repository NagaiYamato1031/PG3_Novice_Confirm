#include "InputHandler.h"

#include "Input.h"

ICommand* InputHandler::HandleInput() {
	if (Input::GetInstance()->PushKey(DIK_A)) {
		return pressKeyA_;
	}
	if (Input::GetInstance()->PushKey(DIK_D)) {
		return pressKeyD_;
	}

	return nullptr;
}

void InputHandler::AssingMoveLeftCommand2PreesKeyA() {
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

void InputHandler::AssingMoveRightCommand2PreesKeyD() {
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}