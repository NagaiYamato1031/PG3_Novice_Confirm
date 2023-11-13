#include "Enemy.h"

void Enemy::Initialize() {
	position_ = {640, 120};
	size_ = {20.0f, 20.0f};
	velocity_ = {4.0f, 0.0f};
	color_ = 0xAA3333FF;
	isActive_ = true;
}

void Enemy::Initialize(const Vector2& pos) {
	position_ = pos;
	size_ = {20.0f, 20.0f};
	velocity_ = {4.0f, 0.0f};
	color_ = 0xAA3333FF;
	isActive_ = true;
}

void Enemy::Update() {

	if (!isActive_) {
		return;
	}

	if (position_.x - size_.x < 0 || 1280 < position_.x + size_.x) {
		velocity_ *= -1;
	}

	position_ += velocity_;
}

void Enemy::Draw() {
	if (!isActive_) {
		return;
	}
	// 描画
	Novice::DrawEllipse(
	    (int)position_.x, (int)position_.y, (int)size_.x, (int)size_.y, 0.0f, color_,
	    kFillModeSolid);
}

void Enemy::OnCollision() { isActive_ = false; }
