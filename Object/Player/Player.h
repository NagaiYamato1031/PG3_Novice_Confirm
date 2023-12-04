#pragma once

#include <vector>

#include "../IObject.h"
#include "./InputManager/InputManager.h"

class Bullet;

class Player : public IObject {
private:
	InputManager* input_ = nullptr;

	const float kMoveSpeed_ = 5.0f;

public:
	void Initialize() override;

	void Update() override;

	void Draw() override;

public:
	void MoveRight();

	void MoveLeft();
};