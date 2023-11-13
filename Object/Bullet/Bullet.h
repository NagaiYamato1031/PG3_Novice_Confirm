#pragma once

#include "../IObject.h"

class Bullet : public IObject {
private:
	bool isActive_ = false;

public:
	void Initialize() override;

	void Update() override;

	void Draw() override;

	void OnCollision() override;

public:

	bool GetIsActive() const { return isActive_; }

	void OnShot(const Vector2& pos);

};