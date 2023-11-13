#pragma once

#include "../IObject.h"

class Enemy : public IObject {
private:


public:
	void Initialize() override;
	void Initialize(const Vector2& pos);

	void Update() override;

	void Draw() override;

	void OnCollision() override;

private:

};