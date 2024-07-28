#pragma once
#include "Vector2.h"
#include <iostream>
#include "Novice.h"

class Bullet
{
private:
	Vector2 pos_;
	float speed_;
	int radius_;
	uint32_t color_;

	bool isShot_ = false;

public:
	void Initialize(Vector2& pos, float speed, int radius, uint32_t color);
	void Update();
	void Draw();

	void IsCollide(Vector2& pos, int radius);

	const bool GetIsShot() const { return isShot_; }

	void SetIsShot(bool boolean) { isShot_ = boolean; }
};

