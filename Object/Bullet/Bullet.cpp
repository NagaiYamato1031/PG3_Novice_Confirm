#include "Bullet.h"

void Bullet::Initialize() {
	position_ = {640, 360};
	size_ = {15.0f, 15.0f};
	velocity_ = {0.0f, 0.0f};
	color_ = 0x777777FF;
}

void Bullet::Update() { 
	if (!isActive_) {
		return;
	}
	position_ += velocity_; 
	if (position_.y - size_.y < 0) {
		isActive_ = false;
	}
}

void Bullet::Draw() {
	// 描画
	if (isActive_) {

		Novice::DrawEllipse(
		    (int)position_.x, (int)position_.y, (int)size_.x, (int)size_.y, 0.0f, color_,
		    kFillModeSolid);
	}
}

void Bullet::OnCollision() { isActive_ = false; }

void Bullet::OnShot(const Vector2& pos) {

	position_ = pos;

	velocity_.y = -6.0f;

	isActive_ = true;
}
