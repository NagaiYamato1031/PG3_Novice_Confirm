#pragma once

#include <memory>

#include "../IScene.h"
#include "./Object/ObjectList.h"

class StageScene : public IScene 
{
private:

	std::unique_ptr<Player> player_;

	std::unique_ptr<Bullet> bullets_[16];

	std::unique_ptr<Enemy> enemys_[4];


public:
	~StageScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;
};