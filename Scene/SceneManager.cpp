#include "SceneManager.h"

#include "./Scene/SceneList.h"
#include <Novice.h>

SceneManager::SceneManager() {
	sceneArr_[TITLE].reset(new TitleScene);
	sceneArr_[STAGE].reset(new StageScene);
	sceneArr_[CLEAR].reset(new ClearScene);

	prevSceneNo_ = TITLE;
	currentSceneNo_ = TITLE;
	sceneArr_[currentSceneNo_]->Initialize();
	inputManager_ = InputManager::GetInstance();
}

SceneManager::~SceneManager() {}

int SceneManager::Run() {
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		inputManager_->Update();

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}

		sceneArr_[currentSceneNo_]->Update();

		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		if (inputManager_->TrrigerKey(DIK_ESCAPE)) {
			break;
		}
	}
	return 0;
}
