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

void Player::Initialize(std::vector<Bullet*>& bullets) {
	position_ = {640, 360};
	size_ = {20.0f, 20.0f};
	velocity_ = {0.0f, 0.0f};
	color_ = 0xFFFFFFFF;

	input_ = InputManager::GetInstance();

	isActive_ = true;

	bullets_ = bullets;
}

void Player::Update() {
	GetOparate();

	position_ += velocity_;
}

void Player::Draw() {
	// 描画
	GetOparate();
	Novice::DrawEllipse(
	    (int)position_.x, (int)position_.y, (int)size_.x, (int)size_.y, 0.0f, color_,
	    kFillModeSolid);
}

void Player::GetOparate() {

	float kSpeed = 5.0f;

	velocity_ = {0.0f, 0.0f};

	if (input_->PressKey(DIK_A)) {
		velocity_.x -= kSpeed;
	}
	if (input_->PressKey(DIK_D)) {
		velocity_.x += kSpeed;
	}
	if (input_->PressKey(DIK_W)) {
		velocity_.y -= kSpeed;
	}
	if (input_->PressKey(DIK_S)) {
		velocity_.y += kSpeed;
	}

	if (input_->TrrigerKey(DIK_SPACE)) {
		Shot();
	}
}
void Player::Shot() {
	for (Bullet* bullet : bullets_) {
		if (!bullet->GetIsActive()) {
			bullet->OnShot(position_);
			break;
		}
	}
}
