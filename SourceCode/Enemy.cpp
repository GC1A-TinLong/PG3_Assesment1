#include "Enemy.h"

void Enemy::Initialize(Vector2& pos, float speed, int radius, uint32_t color)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	color_ = color;
}

void Enemy::Update()
{
	pos_.x += speed_;
	if (pos_.x >= 1280 - radius_ || pos_.x <= radius_) {
		speed_ *= -1;
	}
}

void Enemy::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0, color_, kFillModeSolid);
}
