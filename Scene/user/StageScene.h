#pragma once

#include <memory>

#include "../IScene.h"

class StageScene : public IScene 
{
private:

public:
	~StageScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;
};