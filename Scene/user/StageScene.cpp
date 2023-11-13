#include "StageScene.h"

#include "./Object/Player/Player.h"

StageScene::~StageScene() {}

void StageScene::Initialize() {
	std::vector<Bullet*> bullets;
	for (size_t i = 0; i < 16; i++) {
		bullets_[i].reset(new Bullet);
		bullets_[i]->Initialize();
		bullets.push_back(bullets_[i].get());
	}

	player_.reset(new Player);
	player_->Initialize(bullets);

	for (size_t i = 0; i < 4; i++) {
		Vector2 pos{(float)i * 240.0f + 100, (float)i * 50.0f + 50.0f};
		enemys_[i].reset(new Enemy);
		enemys_[i]->Initialize(pos);
	}
	input_ = InputManager::GetInstance();
}

void StageScene::Update() {

	for (size_t i = 0; i < 4; i++) {
		enemys_[i]->Update();
	}

	for (size_t i = 0; i < 16; i++) {
		bullets_[i]->Update();
	}

	player_->Update();

	// 当たり判定計算
	for (size_t i = 0; i < 4; i++) {
		if (!enemys_[i]->GetIsActive()) {
			continue;
		} else {
			Vector2 enemySize = enemys_[i]->GetSize();
			for (size_t j = 0; j < 16; j++) {
				if (!bullets_[j]->GetIsActive()) {
					continue;
				}
				// 円
				Vector2 subtract = enemys_[i]->GetPosition() - bullets_[j]->GetPosition();
				float distance = Mymath::Length(subtract);
				Vector2 bulletSize = bullets_[j]->GetSize();
				if (distance < enemySize.x + bulletSize.x ||
				    distance < enemySize.y + bulletSize.y) {
					enemys_[i]->OnCollision();
					bullets_[j]->OnCollision();
					break;
				}
			}
		}
	}
	// クリア判定
	bool isClear = true;
	for (size_t i = 0; i < 4; i++) {
		if (enemys_[i]->GetIsActive()) {
			isClear = false;
		}
	}

	if (isClear) {
		sSceneNo_ = CLEAR;
	}
}

void StageScene::Draw() {
	for (size_t i = 0; i < 4; i++) {
		enemys_[i]->Draw();
	}
	for (size_t i = 0; i < 16; i++) {
		bullets_[i]->Draw();
	}

	player_->Draw();
}
