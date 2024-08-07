#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	for (auto* bullets : bullets_) {
		delete bullets;
	}
	bullets_.clear();
}

void Player::Initialize(Vector2& pos, float speed, int radius, uint32_t color)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	color_ = color;
	isShot = false;

	bullets_.resize(kBulletNum);
	for (auto& bullets : bullets_) {	// "&" <- 参照だけ本体に影響与えられる
		Vector2 bulletPos = { -1000.0f,0 };
		bullets = new Bullet;
		bullets->Initialize(bulletPos, 20.0f, 10, RED);
	}
}

void Player::Update()
{
	MoveControl();
	ShootControl();
}

void Player::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0, color_, kFillModeSolid);

	for (auto* bullets : bullets_) {
		if (bullets) {
			bullets->Draw();
		}
	}
}

void Player::MoveControl()
{
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

void Player::ShootControl()
{
	if (Input::GetInstance()->PushKey(DIK_SPACE) && bulletBreak == false) {
		bulletBreak = true;
		for (auto* bullets : bullets_) {
			if (!bullets->GetIsShot()) {
				bullets->Initialize(pos_, 20.0f, 10, RED);
			}
		}

		for (auto* bullets : bullets_) {
			if (!bullets->GetIsShot() && kBulletCD == 0) {
 				bullets->SetIsShot(true);
				break;
			}
		}
	}
	else if (bulletBreak) {
		kBulletCD++;
		if (kBulletCD >= 4) {
			kBulletCD = 0;
			bulletBreak = false;
		}
	}

	for (auto* bullets : bullets_) {
		bullets->Update();
	}
}
