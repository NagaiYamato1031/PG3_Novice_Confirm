#pragma once

#include "IScene.h"
#include <memory>
#include "./InputManager/InputManager.h"

class SceneManager {
private:
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;

	InputManager* inputManager_ = nullptr;

public:
	SceneManager();
	~SceneManager();

	// ゲームループ
	int Run();
};