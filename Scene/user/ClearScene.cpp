#include "ClearScene.h"

ClearScene::~ClearScene() {}

void ClearScene::Initialize() { input_ = InputManager::GetInstance(); }

void ClearScene::Update() {
	if (input_->TrrigerKey(DIK_SPACE)) {
		sSceneNo_ = TITLE;
	}
}

void ClearScene::Draw() { Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x33AA33FF, kFillModeSolid); }
