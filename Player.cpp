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

	bullets_.resize(kBulletNum);
	for (auto& bullets : bullets_) {
		Vector2 bulletPos = { -1000.0f,0 };
		bullets = new Bullet;
		bullets->Initialize(bulletPos, 20.0f, 10, RED);
	}

	//for (int32_t i = 0; i < kBulletNum; i++) {
	//	Vector2 bulletPos = { -1000.0f,0 };
	//	Bullet* bullets = new Bullet;
	//	bullets->Initialize(bulletPos, 20.0f, 10, RED);

	//	bullets_.push_back(bullets);	// adding the value to the last of the list
	//}
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
		if (bullets->GetIsShot()) {
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
	if(Input::GetInstance()->TriggerKey(DIK_SPACE)){
		for (auto* bullets : bullets_) {
			bullets->Initialize(pos_, 20.0f, 10, RED);
		}
	}
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		isShot = true;
	}
	else if (Input::GetInstance()->TriggerKey(DIK_SPACE) == false) {
		isShot = false;
	}

	if (isShot) {
		for (auto* bullets : bullets_) {
			bullets->SetIsShot(true);
		}
	}
	for (auto* bullets : bullets_) {
		if (bullets->GetIsShot()) {
			bullets->Update();
		}
	}
}
