#pragma once
#include "Vector2.h"
#include "iostream"

class Character
{
protected:
	Vector2 pos_{};
	float speed_ = 0;
	int radius_ = 0;
	uint32_t color_ = 0;

	bool isShot = false;

public:
	virtual void Initialize(Vector2& pos, float speed, int radius, uint32_t color) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

