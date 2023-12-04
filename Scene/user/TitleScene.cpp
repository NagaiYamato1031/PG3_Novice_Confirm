#include "TitleScene.h"

TitleScene::~TitleScene() {}

void TitleScene::Initialize() {
	input_ = InputManager::GetInstance();
	player_.reset(new Player);
	player_->Initialize();

	inputHandler_.reset(new InputHandler);

	inputHandler_->AssingMoveLeftCommand2PreesKeyA();
	inputHandler_->AssingMoveRightCommand2PreesKeyD();
}

void TitleScene::Update() {
	command_ = inputHandler_->HandleInput();

	if (this->command_) {
		command_->Exec(*player_);
	}

	player_->Update();
}

void TitleScene::Draw() { player_->Draw(); }
