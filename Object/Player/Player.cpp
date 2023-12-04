#include "Player.h"

#include "../Bullet/Bullet.h"

void Player::Initialize() {
	position_ = {640, 360};
	size_ = {20.0f, 20.0f};
	velocity_ = {0.0f, 0.0f};
	color_ = 0xFFFFFFFF;

	input_ = InputManager::GetInstance();

	isActive_ = true;
}


void Player::Update() {

	position_ += velocity_;
}

void Player::Draw() {
	// 描画
	Novice::DrawEllipse(
	    (int)position_.x, (int)position_.y, (int)size_.x, (int)size_.y, 0.0f, color_,
	    kFillModeSolid);
}

void Player::MoveRight() { position_.x += kMoveSpeed_; }

void Player::MoveLeft() { position_.x -= kMoveSpeed_; }
