#include "Player.h"

void Player::Initialize(Vector2& pos, float speed, int radius, uint32_t color)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	color_ = color;
}

void Player::Update()
{
	MoveControl();
	ShootControl();
}

void Player::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0, color_, kFillModeSolid);
}

void Player::MoveControl()
{
	if (isShot) {
		if (Input::GetInstance()->PushKey(DIK_W)) {
			pos_.y -= speed_;
		}
		if (Input::GetInstance()->PushKey(DIK_S)) {
			pos_.y += speed_;
		}
		if (Input::GetInstance()->PushKey(DIK_A)) {
			pos_.x -= speed_;
		}
		if (Input::GetInstance()->PushKey(DIK_D)) {
			pos_.x += speed_;
		}
	}
}

void Player::ShootControl()
{
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		isShot = true;
	}
	else if (Input::GetInstance()->TriggerKey(DIK_SPACE) == false) {
		isShot = false;
	}
}
