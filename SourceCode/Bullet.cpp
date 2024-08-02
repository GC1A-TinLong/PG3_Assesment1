#include "Bullet.h"

void Bullet::Initialize(Vector2& pos, float speed, int radius, uint32_t color)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	color_ = color;
}

void Bullet::Update()
{
	if (isShot_) {
		pos_.y -= speed_;
	}
	if (pos_.y <= -radius_) {
		isShot_ = false;
	}
}

void Bullet::Draw()
{
	if (isShot_) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0, color_, kFillModeSolid);
	}
}
