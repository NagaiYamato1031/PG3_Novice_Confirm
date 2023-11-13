#pragma once

#include "../IScene.h"

class ClearScene : public IScene {
private:
public:
	~ClearScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;
};