#pragma once

#include <vector>

#include "../IObject.h"
#include "./InputManager/InputManager.h"

class Bullet;

class Player : public IObject {
private:

	InputManager* input_ = nullptr;

	std::vector<Bullet*> bullets_;

public:
	void Initialize() override;
	void Initialize(std::vector<Bullet*>& bullets);

	void Update() override;

	void Draw() override;

private:
	void GetOparate();

	void Shot();
};