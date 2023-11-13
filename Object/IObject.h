#pragma once

#include "./Math/Mymath.h"
#include <Novice.h>

class IObject {
protected:
	Vector2 position_ = {0.0f, 0.0f};
	Vector2 velocity_ = {0.0f, 0.0f};
	Vector2 size_ = {20.0f, 20.0f};

	int color_ = 0xFFFFFFFF;

	bool isActive_ = true;

public:
	virtual ~IObject() {}

	virtual void Initialize() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void OnCollision();

public:

	const Vector2& GetPosition() const { return position_; }
	const Vector2& GetSize() const { return size_; }
	bool GetIsActive() const { return isActive_; }
};