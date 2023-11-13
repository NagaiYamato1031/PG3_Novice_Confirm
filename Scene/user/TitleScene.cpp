#include "TitleScene.h"

TitleScene::~TitleScene() {}

void TitleScene::Initialize() { input_ = InputManager::GetInstance(); }

void TitleScene::Update() {
	if (input_->TrrigerKey(DIK_SPACE)) {
		sSceneNo_ = STAGE;
	}
}

void TitleScene::Draw() {}
